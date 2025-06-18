/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:17:42 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/10 17:27:27 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del (lst->content);
	free(lst);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_del(void *content)
{
	free(content);
}

int	main(void)
{
	char *str = ft_strdup("chau nodo");
	t_list *nodo = ft_lstnew(str);

	printf("Antes de borrar: %s\n", (char *)nodo->content);

	ft_lstdelone(nodo, ft_del);

	printf("Nodo borrado correctamente %s.\n", (char *)nodo->content);

	return (0);
}
*/
