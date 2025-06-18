/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:30:53 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 16:35:23 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*msg = "Hola, soy un nodo!";
	t_list	*node = ft_lstnew((void *)msg);

	if (node)
	{
		printf("Contenido del nodo: %s\n", (char *)node->content);
		if (node->next == NULL)
			printf("Siguiente nodo: NULL (correcto)\n");
	}

	free(node);
	return (0);
}
*/
