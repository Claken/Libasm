# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_size.s                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 21:01:23 by sachouam          #+#    #+#              #
#    Updated: 2020/05/05 21:01:31 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text
	global	ft_list_size
		; rdi == t_list *list

ft_list_size:
		mov	rdx, 0
		mov	rsi, [rdi]
		cmp	rsi, 0
		je	null
while:
		cmp	rsi, 0
		je	return
		mov	rsi, [rdi]
		inc	rdx
		jmp	while
return:
		mov	rax, rdx
		ret
null:		mov	rax, 0
		ret
