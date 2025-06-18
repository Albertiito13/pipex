/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:25:34 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 16:41:27 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (0);
	res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
/*
#include <stdio.h>
#include "libft.h"

// Función 1: convierte caracteres en índice par a mayúsculas
char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32); // pasa a mayúscula
	return (c);
}

// Función 2: convierte todos los caracteres en 'X'
char	to_x(unsigned int i, char c)
{
	(void)i; // ignoramos el índice
	(void)c;
	return ('X');
}

// Función 3: suma el índice al carácter (cambia letras)
char	shift_by_index(unsigned int i, char c)
{
	return (c + 13);
}

int	main(void)
{
	char	*original = "hola mundo";
	char	*result1;
	char	*result2;
	char	*result3;

	result1 = ft_strmapi(original, to_upper_even);
	result2 = ft_strmapi(original, to_x);
	result3 = ft_strmapi(original, shift_by_index);

	printf("Original        : %s\n", original);
	printf("Mayus pares     : %s\n", result1);
	printf("Todo X          : %s\n", result2);
	printf("Shift by index  : %s\n", result3);

	// Liberar memoria
	free(result1);
	free(result2);
	free(result3);

	return (0);
}

*/
