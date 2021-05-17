/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:49:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/12 12:29:49 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libasm_bonus.h"

void	list_push_front(t_list **begin_list, void *data)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return ;
	list->next = *begin_list;
	list->data = data;
	*begin_list = list;
}

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	if (!(current = lst))
		return (0);
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *svg;

	svg = NULL;
	if (*lst && del)
	{
		while (*lst)
		{
			svg = (*lst)->next;
			free(*lst);
			*lst = svg;
		}
	}
}

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
/*
void	ft_content_zero(void *content)
{
	printf("iter : %d\n", (int)content);
}
*/
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

	if (!(element = malloc(sizeof(t_list)))
	|| (!(cont = malloc(sizeof(*content)))))
		return (NULL);
	element->data = cont;
	element->next = NULL;
	return (element);
}

int		main(void)
{
	t_list	*Liste = NULL;
	t_list	*element;
	t_list	*element2;
	t_list	*element3;
	t_list	*element4;
	t_list	*element5;
	t_list	*element6;
	t_list	*element7;
	t_list	*element8;

	t_list	*svg;
	t_list	*newlist;
	int		d;

	d			= 0;
	printf("size libft  quand Liste est NULL = %d\n", ft_lstsize(Liste));
	printf("size libasm quand Liste est NULL = %d\n", ft_list_size(Liste));
	printf("\n");
	if (!(Liste = ft_lstnew((void *)1))
	|| (!(element = ft_lstnew((void *)2)))
	|| (!(element2 = ft_lstnew((void *)3)))
	|| (!(element3 = ft_lstnew((void *)4))))
		return (0);
	ft_lstadd_back(&Liste, element);
	ft_lstadd_back(&Liste, element2);
	ft_lstadd_back(&Liste, element3);
	svg = Liste;
	while (Liste)
	{
		d++;
		printf("Liste elem%d = %d\n", d, (int)Liste->data);
		Liste = Liste->next;
	}
	printf("\n");
	Liste = svg;
	printf("size libasm = %d\n", ft_list_size(Liste));
	printf("size libft  = %d\n", ft_lstsize(Liste));
	printf("\n");
	ft_lstclear(&Liste, &free);
	if (!(Liste = ft_lstnew(5))
	|| (!(element = ft_lstnew((void *)4545)))
	|| (!(element2 = ft_lstnew((void *)4511145)))
	|| (!(element3 = ft_lstnew((void *)454555)))
	|| (!(element4 = ft_lstnew((void *)4545)))
	|| (!(element5 = ft_lstnew((void *)4545)))
	|| (!(element6 = ft_lstnew((void *)4545)))
	|| (!(element7 = ft_lstnew((void *)856)))
	|| (!(element8 = ft_lstnew((void *)45454545))))
		return (0);
	ft_lstadd_back(&Liste, element);
	ft_lstadd_back(&Liste, element2);
	ft_lstadd_back(&Liste, element3);
	ft_lstadd_back(&Liste, element4);
	ft_lstadd_back(&Liste, element5);
	ft_lstadd_back(&Liste, element6);
	ft_lstadd_back(&Liste, element7);
	ft_lstadd_back(&Liste, element8);
	svg = Liste;
	d = 0;
	while (Liste)
	{
		d++;
		printf("Liste elem%d = %d\n", d, (int)Liste->data);
		Liste = Liste->next;
	}
	printf("\n");
	Liste = svg;
	printf("size libasm = %d\n", ft_list_size(Liste));
	printf("size libft  = %d\n", ft_lstsize(Liste));
	ft_lstclear(&Liste, &free);
	return (0);
}
