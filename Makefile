ASM_FILES = $(wildcard asm/*.s include/asm/*.s)
C_SOURCES = $(wildcard kernel/*.c libc/*.c)
HEADERS = $(wildcard include/*.h include/kernel/*.h)

ASM_OBJ_FILES = ${ASM_FILES:.s=.o}
C_OBJ_FILES = ${C_SOURCES:.c=.o}

C_FLAGS = -std=c99 -ffreestanding -mgeneral-regs-only -Iinclude

all: run

%.o: ${ASM_FILES}
	aarch64-linux-gnu-gcc -c $< -o $@

%.o: ${C_SOURCES} ${HEADERS}
	aarch64-linux-gnu-gcc ${C_FLAGS} -c $<

run: ${ASM_OBJ_FILES} ${C_OBJ_FILES}
	aarch64-linux-gnu-ld -nostdlib -T linker.ld -o kernel $^
	aarch64-linux-gnu-objcopy -O binary kernel kernel8.img
	dd if=os.img >> kernel8.img

# %.o: %.s:
# 	aarch64-linux-gnu-gcc -c $< -o $@

# %.o: %.c ${HEADERS}
# 	aarch64-linux-gnu-gcc -o $@ -c $< ${C_FLAGS}

# lumaos.bin: linker.ld
# 	aarch64-linux-gnu-ld -nostdlib -T $< -o kernel ${ASM_OBJ_FILES} ${C_OBJ_FILES}

# install: lumaos.bin
# 	mkdir -p isodir/boot/grub
# 	cp $< isodir/boot/$<
# 	cp grub.cfg isodir/boot/grub
# 	grub-mkrescue -o ${ISO} isodir
# 	rm -rf isodir

# run:
# 	qemu-system-i686 -M rasp3 

clean:
	rm bin/*.bin *.o *.dis *.elf
	rm kernel/*.o
	rm asm/*.o
	rm drivers/*.o
	rm libc/*.o