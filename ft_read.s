# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/01 12:33:10 by sachouam          #+#    #+#              #
#    Updated: 2021/05/05 11:33:11 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section	.text
		global	ft_read
		extern	__errno_location

ft_read:
		mov		rax, 0
		syscall
		cmp		rax, 0;
		jl		errno
		ret
errno:
		neg		rax
		mov		rdi, rax
		call	__errno_location wrt ..plt
		mov		[rax], rdi
		mov		rax, -1
		ret

