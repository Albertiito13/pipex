/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:02:01 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 15:31:59 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	dst_len = i;
	while (src[j] && (i + 1) < size)
		dst[i++] = src[j++];
	if (dst_len < size)
		dst[i] = '\0';
	while (src[j])
		j++;
	return (dst_len + j);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[15] = "Hola";
    size_t len = ft_strlcat(buffer, " mundo", 10);

    printf("Resultado: %s\n", buffer);   // → Hola mundo
    printf("Tamaño total esperado: %zu\n", len); // → 10

    return 0;
}
*/
