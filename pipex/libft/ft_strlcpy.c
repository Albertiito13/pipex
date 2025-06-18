/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:51:34 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 13:47:28 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char dest[10];
    size_t len = strlcpy(dest, "Hola mundo", sizeof(dest));

    printf("Destino: %s\n", dest);       // → "Hola mund"
    printf("Longitud original: %zu\n", len); // → 10 (longitud de "Hola mundo")

    return 0;
}
*/
