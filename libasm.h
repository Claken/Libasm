#ifndef LIBASM_H

# define LIBASM_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

typedef	struct		s_list
{
	void		*data;
	struct s_list 	*next;
}			t_list;

int			ft_strlen(char const *str);
char			*ft_strcpy(char *dst, char const *src);
int			ft_strcmp(char const *s1, char const *s2);
char			*ft_strdup(char const *s1);
ssize_t			ft_write(int fd, void const *buf, size_t nbyte);
ssize_t			ft_read(int fd, void *buf, size_t nbyte);

void			ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
void			ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *));
int			ft_atoi_base(char *str, char *base);

#endif
