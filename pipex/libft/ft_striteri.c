/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:48:26 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 13:00:06 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
#include "libft.h"

// Función 1: convierte a mayúscula los caracteres en índice impar
void	to_upper_odd(unsigned int i, char *c)
{
	if (i % 2 != 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

// Función 2: reemplaza todos los caracteres por '*'
void	to_asterisk(unsigned int i, char *c)
{
	(void)i;
	*c = '*';
}

// Función 3: desplaza el carácter según su índice
void	shift_by_index(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char	str1[] = "hola mundo";
	char	str2[] = "hola mundo";
	char	str3[] = "hola mundo";

	printf("Original 1      : %s\n", str1);
	ft_striteri(str1, to_upper_odd);
	printf("Mayus impares   : %s\n", str1);

	printf("Original 2      : %s\n", str2);
	ft_striteri(str2, to_asterisk);
	printf("Todo asteriscos : %s\n", str2);

	printf("Original 3      : %s\n", str3);
	ft_striteri(str3, shift_by_index);
	printf("Shift by index  : %s\n", str3);

	return (0);
}
*/
