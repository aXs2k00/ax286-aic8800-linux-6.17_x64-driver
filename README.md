# AIC8800 Linux Driver (amd64)

A repo for the Wi-Fi driver tree patched to compile on newer Linux 6.17+ kernels on `amd64` (`x86_64`).

## Background

The manufacturer-provided Linux package (https://www.fenvi.com/drive.html?keyword=WIFI+6+AX286) is distributed as a `.deb` that targets older kernels and is obsolete for modern linux systems. This repo was created by extracting that Debian package and applying compatibility patches so it builds and runs on Debian-based 64-bit systems on Linux 6.17+.

This repo includes:
- Kernel modules under `drivers/aic8800/`
  - `aic_load_fw`: helper module (exports `get_fw_path()` / `testmode`, etc.)
  - `aic8800_fdrv`: Wi-Fi driver module
- Firmware/config blobs under `fw/` (currently `fw/aic8800DC/`)

## Tested

- Distro family: Debian/Kali/Ubuntu
- Kernel: 6.17.x
- Arch: `x86_64` / `amd64`

## Prerequisites

```bash
sudo apt update
sudo apt install -y build-essential linux-headers-$(uname -r)
```

## Firmware Install (AIC8800DC)

The driver uses a firmware path provided by the `aic_load_fw` module parameter

Recommended layout:

```bash
sudo install -d /lib/firmware/aic8800
sudo cp -av fw/aic8800DC/* /lib/firmware/aic8800/
```

## Build

```bash
make -C drivers/aic8800 clean
make -C drivers/aic8800 -j"$(nproc)"
```

## Install

```bash
sudo make -C drivers/aic8800 install
```

This installs modules into:

- `/lib/modules/$(uname -r)/kernel/drivers/net/wireless/aic8800/`

## Activate

Load the helper module first so you can set the firmware path, then load the Wi-Fi driver:

```bash
sudo modprobe aic_load_fw aic_fw_path=/lib/firmware/aic8800
sudo modprobe aic8800_fdrv
```

Quick checks:

```bash
lsmod | grep -E 'aic_load_fw|aic8800_fdrv' || true
dmesg -T | tail -n 200
ip link
```

## Uninstall / Unload

```bash
sudo modprobe -r aic8800_fdrv aic_load_fw
sudo make -C drivers/aic8800 uninstall
```

## Notes

- If Secure Boot is enabled, unsigned out-of-tree modules may fail to load.
- Firmware binaries and vendor code may have separate licensing/redistribution terms; verify you have the right to use/redistribute them.
