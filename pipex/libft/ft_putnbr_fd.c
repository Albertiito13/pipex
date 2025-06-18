/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:27:41 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 13:36:01 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
/*
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int	fd;

	fd = open("numeros.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("No se pudo abrir el archivo", 2);
		return (1);
	}

	ft_putnbr_fd(42, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(-123456, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(-2147483648, fd); // INT_MIN
	ft_putchar_fd('\n', fd);

	close(fd);
	return (0);
}
*/
