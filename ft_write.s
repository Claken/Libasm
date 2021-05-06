# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 04:20:16 by sachouam          #+#    #+#              #
#    Updated: 2021/05/06 17:28:15 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section	.text
		global	ft_write
		extern	__errno_location

		; rdi == fd : là où on écrit la chaîne
		; rsi == buffer : là où se trouve la chaîne
		; rdx == count : nombre de bytes à écrire

ft_write:
		mov		rax, 1
		syscall
		cmp		rax, 0
		jl		errno
		ret
errno:
		neg		rax
		mov		rdi, rax
		call	__errno_location wrt ..plt
		mov		[rax], rdi
		mov		rax, -1
		ret
