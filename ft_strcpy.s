# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 12:33:44 by sachouam          #+#    #+#              #
#    Updated: 2021/05/09 21:04:08 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text
		global	ft_strcpy
		; rdi == chaine de dest
		; rsi == chaine source
ft_strcpy:
		mov	rdx, 0
while:
		mov	al, [rsi+rdx]
		cmp	al, 0
		je	return
		mov	[rdi+rdx], al
		inc	rdx
		jmp	while
return:
		mov	[rdi+rdx], al
		mov	rax, rdi
		ret
