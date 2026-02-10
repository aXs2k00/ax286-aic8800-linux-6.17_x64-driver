savedcmd_aic8800_fdrv/aic8800_fdrv.o := x86_64-linux-gnu-ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o aic8800_fdrv/aic8800_fdrv.o @aic8800_fdrv/aic8800_fdrv.mod  ; /usr/src/linux-headers-6.17.10+kali-amd64/tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --ibt --orc --retpoline --rethunk --sls --static-call --uaccess --prefix=16  --link  --module aic8800_fdrv/aic8800_fdrv.o

aic8800_fdrv/aic8800_fdrv.o: $(wildcard /usr/src/linux-headers-6.17.10+kali-amd64/tools/objtool/objtool)
