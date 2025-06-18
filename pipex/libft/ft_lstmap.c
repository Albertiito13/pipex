/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:39:44 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 18:34:08 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*dup_uppercase(void *content)
{
	char *str = (char *)content;
	char *new = strdup(str);
	int i = 0;
	while (new[i])
	{
		if (new[i] >= 'a' && new[i] <= 'z')
			new[i] -= 32;
		i++;
	}
	return (new);
}

void	del_str(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *n1 = ft_lstnew(strdup("hola"));
	t_list *n2 = ft_lstnew(strdup("mundo"));
	t_list *n3 = ft_lstnew(strdup("libft"));

	n1->next = n2;
	n2->next = n3;

	t_list *nueva = ft_lstmap(n1, dup_uppercase, del_str);

	printf("Original:\n");
	for (t_list *tmp = n1; tmp; tmp = tmp->next)
		printf("- %s\n", (char *)tmp->content);

	printf("\nNueva:\n");
	for (t_list *tmp = nueva; tmp; tmp = tmp->next)
		printf("- %s\n", (char *)tmp->content);

	ft_lstclear(&n1, del_str);
	ft_lstclear(&nueva, del_str);

	return (0);
}
*/
