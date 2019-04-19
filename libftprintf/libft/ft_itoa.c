/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 18:35:42 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:32:19 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_minus(int n)
{
	if (n < 0)
	{
		return (1);
	}
	else
		return (0);
}

static int	ft_size(long long int n)
{
	int count;

	count = 0;
	if (ft_minus(n) == 1)
	{
		count = 1;
		n *= -1;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	long long	num;
	char		*result;
	int			size;
	int			sign;

	num = n;
	sign = num;
	size = ft_size(num);
	if (num < 0)
		num *= -1;
	if (!(result = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	result[size--] = '\0';
	while (size >= 0)
	{
		result[size] = num % 10 + '0';
		num = num / 10;
		size--;
		if (ft_minus(sign) == 1 && size == 0)
		{
			result[size] = '-';
			size--;
		}
	}
	return (result);
}
