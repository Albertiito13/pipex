/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:09:43 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 17:16:22 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list *n1 = ft_lstnew("Hola");
	t_list *n2 = ft_lstnew("cómo");
	t_list *n3 = ft_lstnew("estás?");
	t_list *nuevo = ft_lstnew("yo estoy bien :)");

	n1->next = n2;
	n2->next = n3;

	ft_lstadd_back(&n1, nuevo);

	t_list *actual = n1;
	while (actual)
	{
		printf("%s\n", (char *)actual->content);
		actual = actual->next;
	}

	return (0);
}
*/
