/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:58 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 12:41:30 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_uint		*sha224_init(t_uint *hash)
{
	hash = (t_uint*)malloc(sizeof(t_uint) * 8);
	hash[0] = 0xc1059ed8;
	hash[1] = 0x367cd507;
	hash[2] = 0x3070dd17;
	hash[3] = 0xf70e5939;
	hash[4] = 0xffc00b31;
	hash[5] = 0x68581511;
	hash[6] = 0x64f98fa7;
	hash[7] = 0xbefa4fa4;
	return (hash);
}

void	sha224_print(t_uint *hash)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		ft_printf("%.8x", hash[i]);
		i++;
	}
	free(hash);
}

void	sha224(char *input, size_t len)
{
	ssize_t	size;
	t_uchar	*new_input;
	t_uint	*arr;
	t_uint	*hash;

	size = define_size(len);
	new_input = align(size, input);
	hash = sha224_init(NULL);
	arr = sha256_to_int(new_input, size / 4, size);
	arr = sha224_len((len * 8), arr, ((size / 4) - 1));
	hash = sha256_main_loop(size, arr, hash);
	sha224_print(hash);
}
