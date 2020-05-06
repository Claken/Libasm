# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_push_front.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 21:02:14 by sachouam          #+#    #+#              #
#    Updated: 2020/05/05 21:02:18 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text
	global	ft_list_push_front
		; rdi == double pointeur début de liste : **beginlist
		; rsi == nouvelle element de la liste : *new
ft_list_push_front:
		cmp	rsi, 0 ; if (new)
		jne	checkfront
		ret
checkfront:	
		cmp	rdi, 0 ; if (*beginlist)
		jne	newnextbegin
newinbegin:
		mov	[rdi], rsi ; *beginlist = new
		ret
newnextbegin:
		mov	rsi, [rdi] ; new->next = *beginlist
		jmp	newinbegin
