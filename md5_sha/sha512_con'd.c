/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_con'd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:35:06 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 13:22:49 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_ullint		*sha512_algo(t_ullint *fo, t_ullint *tmp, int i, t_ullint *words)
{
	fo[E0] = (ROR_64(tmp[A], 28) ^ ROR_64(tmp[A], 34) ^ ROR_64(tmp[A], 39));
	fo[MA] = (tmp[A] & tmp[B]) ^ (tmp[A] & tmp[C]) ^ (tmp[B] & tmp[C]);
	fo[T2] = fo[E0] + fo[MA];
	fo[E1] = (ROR_64(tmp[E], 14) ^ ROR_64(tmp[E], 18) ^ ROR_64(tmp[E], 41));
	fo[CH] = (tmp[E] & tmp[F]) ^ ((~tmp[E]) & tmp[G]);
	fo[T1] = tmp[H] + fo[E1] + fo[CH] + sha512_const(i) + words[i];
	return (fo);
}

t_ullint		*sha512_algorithm(t_ullint *tmp, t_ullint *words)
{
	int			i;
	t_ullint	*fo;

	fo = (t_ullint*)malloc(sizeof(t_ullint) * 6);
	i = 0;
	while (i < 80)
	{
		fo = sha512_algo(fo, tmp, i, words);
		tmp[H] = tmp[G];
		tmp[G] = tmp[F];
		tmp[F] = tmp[E];
		tmp[E] = tmp[D] + fo[T1];
		tmp[D] = tmp[C];
		tmp[C] = tmp[B];
		tmp[B] = tmp[A];
		tmp[A] = fo[T1] + fo[T2];
		i++;
	}
	free(fo);
	return (tmp);
}

t_ullint		*sha512_main_loop(t_ullint s, t_ullint *a, t_ullint *hash)
{
	t_ullint	j;
	t_ullint	*tmp;
	t_ullint	*words;
	int			g;

	g = 0;
	j = 0;
	while (j < s)
	{
		words = sha512_transform(NULL, a + g);
		tmp = sha512_hash_cpy(hash);
		tmp = sha512_algorithm(tmp, words);
		hash = sha512_hash_sum(hash, tmp);
		g += 16;
		j += 128;
		free(tmp);
		free(words);
	}
	free(a);
	return (hash);
}

t_ullint		sha512_define_size(t_ullint len)
{
	t_ullint size;

	size = len * 8 + 1;
	while (size % 1024 != 896)
		size++;
	size = (size + 128) / 8;
	return (size);
}

t_uchar			*sha512_align(t_ullint size, char *input)
{
	t_ullint	i;
	t_uchar		*res;

	res = (t_uchar*)malloc(sizeof(t_uchar) * (size));
	i = 0;
	while (i < size && input[i])
	{
		res[i] = (t_uchar)input[i];
		i++;
	}
	res[i++] = 0x80;
	while (i < size)
		res[i++] = 0;
	return (res);
}
