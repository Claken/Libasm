# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_size_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 04:11:55 by sachouam          #+#    #+#              #
#    Updated: 2021/05/04 18:25:40 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text
		global	ft_list_size

		; rdi == t_list *list

ft_list_size:
		mov	rdx, 0
		mov	rsi, rdi
		cmp	rsi, 0
		je	null
while:
		cmp	rsi, 0
		je	return
		mov	rsi, [rsi + 8]
		inc	rdx
		jmp	while
return:
		mov	rax, rdx
		ret
null:
		mov	rax, 0
		ret
