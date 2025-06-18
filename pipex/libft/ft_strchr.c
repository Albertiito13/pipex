/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:02:28 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 16:26:03 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char *s = "hola ";
	printf("%s \n", ft_strchr(s, '\0'));
	printf("%s \n", strchr(s, '\0'));
}
*/
