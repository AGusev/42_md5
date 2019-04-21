/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:13 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 12:40:25 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_uint	fBit(t_uint x, t_uint y, t_uint z)
{
	t_uint	res;

	res = (x & y) | ((~x) & z);
	return (res);
}

t_uint	gBit(t_uint x, t_uint y, t_uint z)
{
	t_uint res;

	res = (x & z) | ((~z) & y);
	return (res);
}

t_uint	hBit(t_uint x, t_uint y, t_uint z)
{
	t_uint res;

	res = x ^ y ^ z;
	return (res);
}

t_uint	lBit(t_uint x, t_uint y, t_uint z)
{
	t_uint res;

	res = y ^ ((~z) | x);
	return (res);
}

t_ullint	ROR_64(t_ullint x, int n)
{
	return(x >> n | x << (64 - n));
}

t_uint	ROR_32(t_uint x, int n)
{
	return(x>> n | x << (32 - n));
}
