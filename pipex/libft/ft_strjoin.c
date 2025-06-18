/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:37:18 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 15:31:18 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!join)
		return (0);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}
/*
#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(const char *s1, const char *s2);

int main(void)
{
	char *s1 = "Hola";
	char *s2 = " mundo";
	char *s3 = "";
	char *s4 = "42";

	char *res1 = ft_strjoin(s1, s2);     // → "Hola mundo"
	char *res2 = ft_strjoin(s3, s4);     // → "42"
	char *res3 = ft_strjoin(s1, s3);     // → "Hola"
	char *res4 = ft_strjoin(s3, s3);     // → ""

	printf("Res1: %s\n", res1);
	printf("Res2: %s\n", res2);
	printf("Res3: %s\n", res3);
	printf("Res4: %s\n", res4);

	free(res1);
	free(res2);
	free(res3);
	free(res4);

	return 0;
}
*/
