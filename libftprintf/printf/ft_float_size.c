/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:02:42 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:31:22 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_fmake(int count, long double num1, t_key *key, int i)
{
	int			elem;

	if (count == 0)
		key->res = ft_strdup("0");
	while (count-- > 0)
	{
		num1 *= 10;
		elem = (int)num1;
		num1 -= elem;
		key->res[i++] = elem + '0';
	}
	return (num1);
}

void		ft_float_size(t_key *key)
{
	int size;
	int len;
	int j;

	if (!key->res)
		key->res = ft_strdup("0.0");
	size = key->p != 0 ? 1 : 0;
	size += key->p == -1 ? 6 : 0;
	size += key->p > 0 ? key->p : 0;
	j = key->res[0] == '-' ? 1 : 0;
	len = ft_strlen(key->res) - j;
	key->fpsize = size + len;
	key->fpsize += key->flags->s || key->flags->p || j ? 1 : 0;
	size = key->fpsize;
	key->wsize = key->w - size > 0 ? key->w : 0;
	size = key->wsize > 0 ? key->w : size;
	key->finsize = size;
}
