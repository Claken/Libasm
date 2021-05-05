# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 12:34:01 by sachouam          #+#    #+#              #
#    Updated: 2021/05/03 17:08:35 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section	.text
		global	ft_strlen
		; rdi == chaine en parametre
ft_strlen:
		mov		rdx, 0
_while:
		mov		cl, [rdi]
		cmp		cl, 0
		je		return
		inc		rdi
		inc		rdx
		jmp		_while
return:
		mov		rax, rdx
		ret
