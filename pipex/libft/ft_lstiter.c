/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:35:09 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 17:38:26 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// Función que convierte el contenido a mayúsculas (en el mismo string)
void	to_uppercase(void *content)
{
	char *str = (char *)content;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int	main(void)
{
	t_list *n1 = ft_lstnew(strdup("hola"));
	t_list *n2 = ft_lstnew(strdup("mundo"));
	t_list *n3 = ft_lstnew(strdup("libft"));

	n1->next = n2;
	n2->next = n3;

	printf("Antes:\n");
	for (t_list *tmp = n1; tmp; tmp = tmp->next)
		printf("- %s\n", (char *)tmp->content);

	ft_lstiter(n1, to_uppercase);

	printf("\nDespués de ft_lstiter:\n");
	for (t_list *tmp = n1; tmp; tmp = tmp->next)
		printf("- %s\n", (char *)tmp->content);

	// Liberar memoria
	ft_lstclear(&n1, free);
	return (0);
}
*/
