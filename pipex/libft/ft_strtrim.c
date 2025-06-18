/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:00:26 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/08 22:26:31 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end -1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *s1 = "   Hola mundo   ";
	char *set = " ";
	char *res1 = ft_strtrim(s1, set);

	char *s2 = "\n\t42Madrid\t\n";
	char *set2 = "\n\t";
	char *res2 = ft_strtrim(s2, set2);

	char *s3 = "xxx42xxx";
	char *set3 = "x";
	char *res3 = ft_strtrim(s3, set3);

	char *s4 = "solo texto";
	char *set4 = "";
	char *res4 = ft_strtrim(s4, set4);

	printf("Res1: '%s'\n", res1); // → 'Hola mundo'
	printf("Res2: '%s'\n", res2); // → '42Madrid'
	printf("Res3: '%s'\n", res3); // → '42'
	printf("Res4: '%s'\n", res4); // → 'solo texto'

	free(res1);
	free(res2);
	free(res3);
	free(res4);

	return 0;
}
*/
