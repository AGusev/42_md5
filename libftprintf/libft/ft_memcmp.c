/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:16:29 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:32:19 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;
	int				res;

	i = 0;
	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (arr1[i] > arr2[i])
		{
			res = arr1[i] - arr2[i];
			return (res);
		}
		else if (arr1[i] < arr2[i])
		{
			res = arr1[i] - arr2[i];
			return (res);
		}
		i++;
		n--;
	}
	return (0);
}
