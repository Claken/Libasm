# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 20:56:10 by sachouam          #+#    #+#              #
#    Updated: 2020/05/05 20:56:16 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global	ft_write

		section	.text

		; rdi == fd : là ou on écrit la chaine
		; rsi == buffer : là ou se trouve la chaine
		; rdx == count : nombre de bytes a ecrire
ft_write:	
		cmp	rdi, 2
		jg	reterror
		cmp	rsi, 0
		je	reterror

		mov	rax, 1
		mov	rdi, rdi
		mov	rsi, rsi
		mov	rdx, rdx
		syscall
		mov	rax, rdx
		ret

reterror:	mov	rax, -1
		ret
