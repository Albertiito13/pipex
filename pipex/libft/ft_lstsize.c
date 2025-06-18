/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:58:45 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 17:01:26 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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

	int total = ft_lstsize(n1);
	printf("La lista tiene %d nodos.\n", total); // Debería imprimir 3

	return (0);
}
*/
