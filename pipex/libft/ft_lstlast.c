/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:03:12 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 17:08:02 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list *n1 = ft_lstnew("Hola");
	t_list *n2 = ft_lstnew("cómo");
	t_list *n3 = ft_lstnew("estás?");
	n1->next = n2;
	n2->next = n3;

	t_list *ultimo = ft_lstlast(n1);
	if (ultimo)
		printf("Último nodo: %s\n", (char *)ultimo->content);

	return (0);
}
*/
