FILENAME = lib

ASM_FILES = $(wildcard *.s)
C_FILES = $(wildcard *.c)

ASM_OBJ_FILES = ${ASM_FILES:.s=.o}
C_OBJ_FILES = ${C_FILES:.c=.o}

C_FLAGS = -std=c99 -ffreestanding -mgeneral-regs-only

all: run

%.o: ${ASM_FILES}
	aarch64-linux-gnu-gcc -c $< -o $@

%.o: ${C_FILES}
	aarch64-linux-gnu-gcc ${C_FLAGS} -c $< -o $@

run: ${ASM_OBJ_FILES} ${C_OBJ_FILES}
	aarch64-linux-gnu-ar rcs lib.a $^

clean:
	rm *.a
	rm *.o