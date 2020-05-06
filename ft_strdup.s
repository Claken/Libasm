# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 20:57:00 by sachouam          #+#    #+#              #
#    Updated: 2020/05/05 20:59:07 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text
	global	ft_strdup
		extern	malloc
	;	rdi == chaine source

	;	rsi == chaine de dest qu'on va crée
	;	rdx == 3eme param qui contiendra la size
	;	rcx == 4eme

ft_strdup:	
		mov	rdx, 0
_whilelen:
		mov     al, [rdi+rdx]
		cmp     al, 0
		je	ft_strdup2
		inc	rdx
		jmp	_whilelen
ft_strdup2:
		push	rdi
		inc	rdx
		mov	rdi, rdx
		call 	malloc wrt ..plt
		;call	malloc
		cmp	rax, 0
		je	null
		mov	rsi, rax
		pop	rdi
		mov	rdx, 0
whilecpy:
		mov     al, [rdi+rdx]
		cmp     al, 0
		je      return
		mov     [rsi+rdx], al
		inc     rdx
		jmp     whilecpy
return:
		mov     [rsi+rdx], al
		mov     rax, rsi
		ret
null:		mov	rax, 0
		ret
