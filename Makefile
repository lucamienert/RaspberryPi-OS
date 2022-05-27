ASM_FILES = $(wildcard asm/*.s include/asm/*.s)
C_SOURCES = $(wildcard kernel/*.c libc/*.c)
HEADERS = $(wildcard include/*.h include/kernel/*.h)

OBJ_FILES = ${ASM_FILES:.s=.o}
OBJ_FILES += ${C_SOURCES:.c=.o}

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

C_FLAGS = -std=c99 -ffreestanding -mgeneral-regs-only -Iinclude

all: run

%.o: %.s
	aarch64-linux-gnu-gcc -c $< -o $@

%.o: %.c ${HEADERS}
	aarch64-linux-gnu-gcc ${C_FLAGS} -c $<

kernel8.img: linker.ld ${OBJ_FILES}
	aarch64-linux-gnu-ld -nostdlib -T linker.ld -o kernel8.elf ${OBJ_FILES}
	aarch64-linux-gnu-objcopy kernel8.elf -O binary kernel8.img

clean:
	rm bin/*.bin *.o *.dis *.elf
	rm kernel/*.o
	rm asm/*.o
	rm drivers/*.o
	rm libc/*.o
