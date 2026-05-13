bits	32				; diretiva NASM para proc. 32 bits
section		.text			; secao de texto
	align	4			; especificacoes para multiboot GRUB 
	dd	0x1BADB002		; magic number
	dd	0x00			; flags
	dd	- (0x1BADB002+0x00)	; checksum - somado com os dois campos anteriores deve dar 0
global	start				; funcao global a ser acessada pelo linker
extern	kmain				; funcao sera localizada no codigo c
start:
	cli				; limpa as interrupcoes
	call kmain			; desvia a execucao para a funcao kmain no codigo c (kernel.c)
	hlt				; interrompe a execucao no endereco de memoria corrente
