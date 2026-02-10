savedcmd_aic_load_fw/aic_load_fw.o := x86_64-linux-gnu-ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o aic_load_fw/aic_load_fw.o @aic_load_fw/aic_load_fw.mod  ; /usr/src/linux-headers-6.17.10+kali-amd64/tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --ibt --orc --retpoline --rethunk --sls --static-call --uaccess --prefix=16  --link  --module aic_load_fw/aic_load_fw.o

aic_load_fw/aic_load_fw.o: $(wildcard /usr/src/linux-headers-6.17.10+kali-amd64/tools/objtool/objtool)
