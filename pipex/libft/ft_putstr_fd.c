/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:11:11 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 13:15:59 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}
/*
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int	fd;

	fd = open("mensaje.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Error abriendo el archivo\n", 2);
		return (1);
	}

	ft_putstr_fd("Hola desde Libft!\n", fd);
	close(fd);

	return (0);
}
*/
