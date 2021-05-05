# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 12:33:24 by sachouam          #+#    #+#              #
#    Updated: 2021/05/05 21:54:49 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text
		global	ft_strcmp
		; rdi == premiere chaine
		; rsi == deuxieme chaine
ft_strcmp:
		cmp	rdi, 0
		je	retzero
		cmp	rsi, 0
		je	retzero
		mov	rdx, 0
while:
		mov	al, [rdi+rdx]
		mov	cl, [rsi+rdx]
		cmp	al, 0
		je	return
		cmp	cl, 0
		je	return
		inc	rdx
		cmp	al, cl
		je	while
return:
	;	cmp	al, cl
	;	jl	retneg
	;	jg	retpos
		mov rax, [rdi+rdx]
		sub rax, [rsi+rdx]
		ret
retzero:
		mov	rax, 0
		ret
;retneg:
;		mov	rax, -1
;		ret
;retpos:
;		mov	rax, 1
;		ret
