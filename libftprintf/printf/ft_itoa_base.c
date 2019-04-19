/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:12:57 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 00:04:29 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		define_size(size_t newval, int size, int b, char **res)
{
	while (newval >= (size_t)b)
	{
		newval = newval / b;
		size++;
	}
	*res = ft_strnew(size);
	return (size);
}

char			*ft_itoa_bss(ssize_t val, int b)
{
	char	*res;
	size_t	newval;
	size_t	vval;
	int		size;
	char	*bla;

	bla = "0123456789abcdef";
	size = 1;
	size = val < 0 && b == 10 ? size + 1 : size;
	newval = val < 0 && b == 10 ? -val : val;
	vval = newval;
	size = define_size(newval, size, b, &res);
	if (val == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (vval)
	{
		res[--size] = bla[vval % b];
		vval = vval / b;
	}
	if (--size == 0)
		res[size] = '-';
	return (res);
}

char			*ft_itoa_bs(size_t val, int b)
{
	char	*res;
	size_t	newval;
	int		size;
	char	*bla;

	bla = "0123456789abcdef";
	size = 1;
	newval = val;
	size = define_size(newval, size, b, &res);
	if (val == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (val)
	{
		res[--size] = bla[val % b];
		val = val / b;
	}
	if (--size == 0)
		res[size] = '-';
	return (res);
}
