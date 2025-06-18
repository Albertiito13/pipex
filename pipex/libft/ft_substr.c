/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:14:57 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 15:49:37 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = (char *)malloc(1);
		if (!sub)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

/*
#include <stdio.h>
#include <stdlib.h>

char *ft_substr(const char *s, unsigned int start, unsigned long len);

int main(void)
{
	char *s1 = "Hola mundo";
	char *sub1 = ft_substr(s1, 5, 3);   // → "mun"
	char *sub2 = ft_substr(s1, 0, 4);   // → "Hola"
	char *sub3 = ft_substr(s1, 20, 5);  // → ""
	char *sub4 = ft_substr(s1, 2, 20);  // → "la mundo"

	printf("Sub1: %s\n", sub1);
	printf("Sub2: %s\n", sub2);
	printf("Sub3: %s\n", sub3);
	printf("Sub4: %s\n", sub4);

	free(sub1);
	free(sub2);
	free(sub3);
	free(sub4);

	return 0;
}
*/
