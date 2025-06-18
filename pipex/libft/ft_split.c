/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:45:06 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/08 23:46:33 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			w++;
		i++;
	}
	return (w);
}

static void	free_split(char **res, int j)
{
	while (--j >= 0)
		free(res[j]);
	free(res);
}

static char	**fill_split(char const *s, char c, char **res, int words)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[j] = ft_substr(s, start, i - start);
			if (!res[j])
				return (free_split(res, j), NULL);
			j++;
		}
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	return (fill_split(s, c, res, words));
}
/*
#include <stdio.h>
#include <stdlib.h>

void	print_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		printf("Parte [%d]: '%s'\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(void)
{
	char *s1 = "Hola mundo 42";
	char *s2 = "   uno  dos tres  ";
	char *s3 = "";
	char *s4 = "sin-separadores";
	char *s5 = "----42---Madrid----";

	printf("Test 1:\n");
	print_split(ft_split(s1, ' '));

	printf("\nTest 2:\n");
	print_split(ft_split(s2, ' '));

	printf("\nTest 3:\n");
	print_split(ft_split(s3, ' '));

	printf("\nTest 4:\n");
	print_split(ft_split(s4, ','));

	printf("\nTest 5:\n");
	print_split(ft_split(s5, '-'));

	return 0;
}
*/
