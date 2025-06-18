/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:25:16 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 16:27:34 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    const char *str = "Hola mundo loco!";

	printf("Última 'o' encontrada en: %s\n", strrchr(str, '\0'));
        printf("Última 'o' encontrada en: %s\n", ft_strrchr(str, '\0'));

    return 0;
}
*/
