/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:52:31 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/12 12:28:48 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int					ft_strlen(char const *str);
char				*ft_strcpy(char *dst, char const *src);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strdup(char const *s1);
ssize_t				ft_write(int fd, void const *buf, size_t nbyte);
ssize_t				ft_read(int fd, void *buf, size_t nbyte);

#endif
