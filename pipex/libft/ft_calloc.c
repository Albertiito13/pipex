/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:15:11 by albcamac          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:19 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	unsigned char	*ptr;
	size_t			i;

	total = count * size;
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (0);
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return ((void *)ptr);
}
/*
#include <stdio.h>

void *ft_calloc(unsigned long count, unsigned long size);

int main()
{
    int *nums = (int *)ft_calloc(10, sizeof(int));
    if (!nums)
        return 1;

    for (int i = 0; i < 10; i++)
        printf("%d ", nums[i]); // → 0 0 0 0 0

    free(nums);
    return 0;
}
*/
