/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:04:10 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 13:06:15 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include "libft.h"

int	main(void)
{
	ft_putchar_fd('A', 1); // imprime 'A' en la consola
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('E', 2); // imprime 'E' en stderr (útil para errores)

	return (0);
}
*/
