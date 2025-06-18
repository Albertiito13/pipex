/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:23:08 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/09 15:30:34 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (1 == ft_isalpha(c) || 1 == ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include "libft.h" // Asegurate de que ft_isalnum esté declarado ahí

int main(void)
{
    char test_chars[] = {'A', 'z', '5', '%', ' ', '\n', '0', 'G'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char c = test_chars[i];
        if (ft_isalnum(c))
            printf("'%c' es alfanumérico ✅\n", c);
        else
            printf("'%c' NO es alfanumérico ❌\n", c);
    }

    return 0;
}
*/
