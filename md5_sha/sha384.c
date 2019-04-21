/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:35:03 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 12:41:34 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_ullint	*sha384_init(t_ullint *hash)
{
	hash = (t_ullint*)malloc(sizeof(t_ullint) * 8);
	hash[0] = 0xcbbb9d5dc1059ed8;
	hash[1] = 0x629a292a367cd507;
	hash[2] = 0x9159015a3070dd17;
	hash[3] = 0x152fecd8f70e5939;
	hash[4] = 0x67332667ffc00b31;
	hash[5] = 0x8eb44a8768581511;
	hash[6] = 0xdb0c2e0d64f98fa7;
	hash[7] = 0x47b5481dbefa4fa4;
	return (hash);
}

void	sha384_print(t_ullint *hash)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_printf("%.16zx", hash[i]);
		i++;
	}
	free(hash);
}

void	sha384(char *input, size_t len)
{
	t_ullint	size;
	t_uchar		*new_input;
	t_ullint	*res;
	t_ullint	*hash;

	size = sha512_define_size(len);
	new_input = sha512_align(size, input);
	res = sha384_init(NULL);
	hash = sha512_to_int(new_input, (ssize_t)size / 8, size);
	hash = sha512_len(len * 8, hash, (size / 8) - 1);
	hash = sha512_main_loop(size, hash, res);
	sha384_print(hash);
}
