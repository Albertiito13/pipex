/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:18:39 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 13:25:43 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
}
/*
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int	fd;

	fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("Error al abrir el archivo", 2);
		return (1);
	}

	ft_putendl_fd("Primera línea del log", fd);
	ft_putendl_fd("Otra línea más", fd);
	close(fd);

	return (0);
}
*/
