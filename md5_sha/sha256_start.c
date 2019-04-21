/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:35:01 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 13:16:41 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_uint		*sha256_main_loop(ssize_t size, t_uint *arr, t_uint *hash)
{
	int		j;
	t_uint	*tmp;
	t_uint	*words;
	int		g;

	g = 0;
	j = 0;
	while (j < size)
	{
		words = sha256_transform(NULL, arr + g);
		tmp = sha256_hash_cpy(hash);
		tmp = sha256_algorithm(tmp, words);
		hash = sha256_hash_sum(hash, tmp);
		g += 16;
		j += 64;
		free(tmp);
		free(words);
	}
	free(arr);
	return (hash);
}

t_uint		*initializeBuff256(t_uint *hash)
{
	hash = (t_uint*)malloc(sizeof(t_uint) * 8);
	hash[0] = 0x6A09E667;
	hash[1] = 0xBB67AE85;
	hash[2] = 0x3C6EF372;
	hash[3] = 0xA54FF53A;
	hash[4] = 0x510E527F;
	hash[5] = 0x9B05688C;
	hash[6] = 0x1F83D9AB;
	hash[7] = 0x5BE0CD19;
	return (hash);
}

t_uint		*sha256_to_int(t_uchar *bef, ssize_t new_size, ssize_t size)
{
	t_uint	*aft;
	int		i;

	i = 0;
	aft = (t_uint*)malloc(sizeof(t_uint) * new_size);
	while (i < new_size)
		aft[i++] = 0;
	size--;
	new_size--;
	while (new_size >= 0)
	{
		aft[new_size] = aft[new_size] | bef[size--] << 0;
		aft[new_size] = aft[new_size] | bef[size--] << 8;
		aft[new_size] = aft[new_size] | bef[size--] << 16;
		aft[new_size] = aft[new_size] | bef[size--] << 24;
		new_size--;
	}
	free(bef);
	return (aft);
}

t_uint		*sha224_len(ssize_t len, t_uint *data, ssize_t i)
{
	while (len)
	{
		data[i] = data[i] | (t_uint)len << 0;
		len = len >> 8;
		data[i] = data[i] | (t_uint)len << 8;
		len = len >> 8;
		data[i] = data[i] | (t_uint)len << 16;
		len = len >> 8;
		data[i] = data[i] | (t_uint)len << 24;
		len = len >> 8;
		i--;
	}
	return (data);
}

void		printHash256(t_uint *hash)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%.8x", hash[i]);
		i++;
	}
}

void		sha256(char *input, size_t len)
{
	ssize_t	size;
	t_uchar	*new_input;
	t_uint	*arr;
	t_uint	*hash;

	size = define_size(len);
	new_input = align(size, input);
	hash = initializeBuff256(NULL);
	arr = sha256_to_int(new_input, size / 4, size);
	arr = sha224_len((len * 8), arr, ((size / 4) - 1));
	hash = sha256_main_loop(size, arr, hash);
	printHash256(hash);
}
