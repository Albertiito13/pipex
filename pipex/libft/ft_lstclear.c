/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:28:47 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 17:34:02 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
/*
#include <stdio.h>
void	ft_del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *n1 = ft_lstnew(ft_strdup("Hola"));
	t_list *n2 = ft_lstnew(ft_strdup("cómo"));
	t_list *n3 = ft_lstnew(ft_strdup("estás?"));

	n1->next = n2;
	n2->next = n3;

	printf("Antes de ft_lstclear:\n");
	t_list *tmp = n1;
	while (tmp)
	{
		printf("- %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&n1, ft_del);

	if (!n1)
		printf("Lista completamente liberada ✅\n");

	return (0);
}
*/
