/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:39:25 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:08 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*nodo1 = ft_lstnew("segundo");
	t_list	*nodo0 = ft_lstnew("primero");

	ft_lstadd_front(&nodo1, nodo0);

	printf("Primer nodo: %s\n", (char *)nodo0->content);
	printf("Siguiente nodo: %s\n", (char *)nodo0->next->content);

	return (0);
}
*/
