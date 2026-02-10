import os
import re

def patch_file(filepath, patch_func):
    if not os.path.exists(filepath):
        print(f"Skipping {filepath}: File not found.")
        return

    with open(filepath, 'r') as f:
        content = f.read()

    new_content = patch_func(content)

    if new_content != content:
        with open(filepath, 'w') as f:
            f.write(new_content)
        print(f"Successfully patched {filepath}")
    else:
        print(f"No changes required for {filepath}")

def process_rwnx_rx(content):
    # Rule 1: Fix cfg80211_rx_spurious_frame (Add 0 as 3rd arg)
    # Pattern looks for: func(arg1, arg2, GFP_...) -> func(arg1, arg2, 0, GFP_...)
    # Using specific lookahead for GFP_ or specific flags common in this driver
    
    # Regex explanation:
    # Capture group 1: generic function call start + 2 args
    # Capture group 2: the comma before the last arg
    pattern_spurious = r'(cfg80211_rx_spurious_frame\s*\([^,]+,\s*[^,]+)(,)'
    if re.search(pattern_spurious, content):
        # We only replace if it doesn't already have 0 (heuristic check handled by regex structure)
        # Note: This regex assumes the call fits standard formatting. 
        # For safety, we explicitly look for the call ending in GFP_ATOMIC or similar if possible,
        # but generic replacement is usually safer for C parsing in python without a full parser.
        content = re.sub(pattern_spurious, r'\1, 0\2', content)

    # Rule 2: Fix cfg80211_rx_unexpected_4addr_frame (Add 0 as 3rd arg)
    pattern_4addr = r'(cfg80211_rx_unexpected_4addr_frame\s*\([^,]+,\s*[^,]+)(,)'
    if re.search(pattern_4addr, content):
        content = re.sub(pattern_4addr, r'\1, 0\2', content)
        
    return content

def process_rwnx_main(content):
    lines = content.split('\n')
    new_lines = []
    
    # Rule 3: Mutex Removal & Rule 5: Ops Table Cleaning
    # We iterate line by line for these as they are simple strict string matches
    
    for line in lines:
        stripped = line.strip()
        
        # Mutex Removal
        # Checks for mutex_lock/unlock on vif->wdev.mtx
        # We also check for __acquire/__release as they usually accompany the lock
        if "vif->wdev.mtx" in line and ("mutex_lock" in line or "mutex_unlock" in line or "__acquire" in line or "__release" in line):
            new_lines.append(f"// {line} /* PATCHED: wdev.mtx removed in 6.x */")
            continue
            
        # Ops Table Cleaning
        # Check for specific struct members
        if stripped.startswith(".change_beacon") or stripped.startswith(".set_tx_power"):
            new_lines.append(f"// {line} /* PATCHED: signature changed in 6.x */")
            continue
            
        new_lines.append(line)
    
    content = '\n'.join(new_lines)

    # Rule 4: Channel Switch API
    # Logic: cfg80211_ch_switch_notify(dev, def, 0, 0) -> (dev, def, 0)
    # We use regex here because arguments might span lines or have spacing variations
    # We specifically look for the version having 4 args where the last two are 0
    
    pattern_ch_switch = r'(cfg80211_ch_switch_notify\s*\([^,]+,\s*[^,]+,\s*0),\s*0\s*\)'
    if re.search(pattern_ch_switch, content):
        content = re.sub(pattern_ch_switch, r'\1)', content)

    return content

if __name__ == "__main__":
    print("Starting AIC8800 Driver Patch for Kernel 6.17...")
    patch_file("rwnx_rx.c", process_rwnx_rx)
    patch_file("rwnx_main.c", process_rwnx_main)
    print("Patching complete.")
