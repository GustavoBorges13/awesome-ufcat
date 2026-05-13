#!/bin/sh
nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c -w kernel.c -o kc.o
gcc -m32 -c -w screen.c -o screen.o
ld -m elf_i386 -T link.ld -o kernel.bin kasm.o screen.o kc.o

