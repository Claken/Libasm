; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;
;     nasm -felf64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

		section	.data
	message	db	"Hello, Batard", 10, 0	; note the newline at the end
	digit	db	0, 10

		
		section	.bss
	name		resb	8
	digitSpace	resb	100

		section	.text
		global    _start

%macro exit 0
	mov	rax, 60
	mov	rdi, 0
	syscall
%endmacro

_start:		
	;	call	_getInput
		push 1
		push 2
;		push 3

;		pop rax
;		call	_printRAXDigit
;		pop rax
;		call	_printRAXDigit
;		pop rax
;		call	_printRAXDigit
		
	;	call	_write

;		mov	rax, 123
	;	call	_print
		call 	_MyFunction1
		add 	rsp, 8
		call	_printRAXDigit
		exit
		;mov	rax, 60			; system call for exit
		;xor	rdi, rdi		; exit code 0
		;syscall			; invoke operating system to exit

_printRAXDigit:
		add	rax, 48
		mov	[digit], al
		mov	rax, 1
		mov	rdi, 1
		mov	rsi, digit
		mov	rdx, 2
		syscall
		ret

_write:
		mov       rax, 1                  ; system call for write
		mov       rdi, 1                  ; file handle 1 is stdout
          	mov       rsi, message            ; address of string to output
          	mov       rdx, 13                 ; number of bytes
          	syscall                           ; invoke operating system to do the write
		ret

_getInput:
		mov	rax, 0
		mov	rdi, 0
		mov	rsi, name
		mov	rdx, 8
		syscall
		ret

_print:
		push 	rax
		mov	rbx, 0
_printLoop:
		inc 	rax
		inc 	rbx
		mov 	cl, [rax]
		cmp 	cl, 0
		jne 	_printLoop

		mov 	rax, 1
		mov 	rdi, 1
		pop 	rsi
		mov 	rdx, rbx
		syscall

		ret

_MyFunction1:
		push rbp		; place rbp sur la stack
		mov rbp, rsp		; place les arguments se trouvant dans rsp dans rbp
		mov rax, [rbp + 8]	; place a dans rax
		mov rdx, [rbp + 12]	; place b dans rax
		add rax, rdx		; add a + b
		pop rbp			; fait sortir rbp de la stack 
		ret			; return
