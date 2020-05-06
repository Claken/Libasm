# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 21:00:28 by sachouam          #+#    #+#              #
#    Updated: 2020/05/05 21:00:32 by sachouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

                global  ft_read

                section .text

                ; rdi == fd : là ou on écrit la chaine
                ; rsi == buffer : là ou se trouve la chaine
                ; rdx == count : nombre de bytes a ecrire
ft_read:
                cmp     rdi, 2
                jg      reterror
                cmp     rsi, 0
                je      reterror

                mov     rax, 0
                mov     rdi, rdi	; unsigned int fd
                mov     rsi, rsi	; char *buf
                mov     rdx, rdx	; size_t count
                syscall
                mov     rax, rdx
                ret

reterror:       mov     rax, -1
                ret
