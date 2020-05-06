/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:49:56 by sachouam          #+#    #+#             */
/*   Updated: 2019/11/11 17:19:29 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libasm.h"

t_list	*ft_lstnew(void *content)
{
	t_list *element;

	if (!(element = malloc(sizeof(t_list))))
		return (NULL);
	element->data = content;
	element->next = NULL;
	return (element);
}

void    ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (new)
	{
		if (!(*alst))
			*alst = new;
		else
		{
			while ((*alst)->next != NULL)
				*alst = (*alst)->next;
			(*alst)->next = new;
			*alst = temp;
		}
	}
}

void	ft_del(void *content)
{
	free(content);
}

void	ft_content_zero(void *content)
{
	printf("iter : %p\n", content);
}

void	*ft_content(void *content)
{
	void *i;
	void *j;
	void *k;

	i = content;
	j = (void *)0;
	k = content;
	while (j++ < k)
		i++;
	return (i);
}

t_list		*ft_lstnew1(void *content)
{
	t_list *element;
	void*	cont;

	if (!(element = malloc(sizeof(t_list))) || (!(cont = malloc(sizeof(*content)))))
		return (NULL);
	element->data = cont;
	element->next = NULL;
	return (element);
}

int		main(void)
{
	t_list	*Liste;
	t_list	*element;
	t_list	*element2;
	t_list	*element3;

	t_list	*svg;
	t_list	*newlist;
	void	*un;
	void	*deux;
	void	*trois;
	void	*quatre;
	int	d;

	un		= (void *)1;
	deux		= (void *)2;
	trois		= (void *)3;
	quatre		= (void *)4;

	d		= 0;
	if (!(Liste = ft_lstnew(un))
	|| (!(element = ft_lstnew(deux)))
	|| (!(element2 = ft_lstnew(trois)))
	|| (!(element3 = ft_lstnew(quatre))))
		return (0);
	ft_lstadd_back(&Liste, element);
	ft_lstadd_back(&Liste, element2);
	ft_list_push_front(&Liste, element3);
	printf("size = %d\n", ft_list_size(Liste));
	svg = Liste;
	while (Liste)
	{
		d++;
		printf("Liste elem%d = %p\n", d, Liste->data);
		Liste = Liste->next;
	}
	Liste = svg;
	//ft_lstclear(&Liste, ft_del);
	free(Liste);
	free(element);
	free(element2);
	//free(element3);
	return (0);
}
