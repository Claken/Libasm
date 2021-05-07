# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 12:33:24 by sachouam          #+#    #+#              #
#    Updated: 2021/05/07 17:13:37 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text
		global	ft_strcmp
		; rdi == premiere chaine
		; rsi == deuxieme chaine
		; rdx
		; rcx
ft_strcmp:
		cmp	rdi, 0
		je	retzero
		cmp	rsi, 0
		je	retzero
while:
		mov al, byte [rdi]
		mov cl, byte [rsi]
		cmp al, 0
		je	return
		cmp	cl, 0
		je	return
		inc rdi
		inc rsi
		cmp al, cl
		je	while
return:
;		mov rax, [rdi]
;		mov rcx, [rsi]
;		sub rax, rcx
;		cmp	rax, 0
		mov eax, [rdi]
		mov edx, [rsi]
		sub eax, edx
		cmp eax, 0
		jl	retneg
		jg	retpos
retzero:
		mov	rax, 0
		ret
retneg:
		mov	rax, -1
		ret
retpos:
		mov	rax, 1
		ret
