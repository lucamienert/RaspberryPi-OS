FILENAME = console

ASM_FILES = $(wildcard *.s)
C_SOURCES = $(wildcard *.c)

ASM_OBJ_FILES = ${ASM_FILES:.s=.o}
C_OBJ_FILES = ${C_SOURCES:.c=.o}

C_FLAGS = -std=c99 -ffreestanding -mgeneral-regs-only

all: run

%.o: ${ASM_FILES}
	aarch64-linux-gnu-gcc -c $< -o $@

%.o: ${C_SOURCES}
	aarch64-linux-gnu-gcc ${C_FLAGS} -c $<

run: ${ASM_OBJ_FILES} ${C_OBJ_FILES}
	aarch64-linux-gnu-ld -nostdlib -T linker.ld -o ${FILENAME} $^ ../lib/library.a
	aarch64-linux-gnu-objcopy -O binary ${FILENAME} ${FILENAME}.bin

clean:
	rm *.bin
	rm *.o