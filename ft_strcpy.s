# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 20:59:38 by sachouam          #+#    #+#              #
#    Updated: 2020/05/05 20:59:47 by sachouam         ###   ########.fr        #
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
