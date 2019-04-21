/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:35:06 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 13:21:53 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_ullint		*sha512_to_int(t_uchar *bef, ssize_t news, t_ullint s)
{
	t_ullint	*aft;
	int			i;
	t_ullint	temp;
	int			b;

	i = 0;
	aft = (t_ullint*)malloc(sizeof(t_ullint) * news);
	while (i < news)
		aft[i++] = 0;
	s--;
	news--;
	while (news >= 0)
	{
		b = 0;
		while (b < 64)
		{
			temp = bef[s--];
			aft[news] = aft[news] | temp << b;
			b += 8;
		}
		news--;
	}
	free(bef);
	return (aft);
}

t_ullint		*sha512_len(t_ullint len, t_ullint *data, t_ullint i)
{
	data[i] = data[i] | len;
	return (data);
}

t_ullint		*sha512_init(t_ullint *hash)
{
	hash = (t_ullint*)malloc(sizeof(t_ullint) * 8);
	hash[0] = 0x6a09e667f3bcc908;
	hash[1] = 0xbb67ae8584caa73b;
	hash[2] = 0x3c6ef372fe94f82b;
	hash[3] = 0xa54ff53a5f1d36f1;
	hash[4] = 0x510e527fade682d1;
	hash[5] = 0x9b05688c2b3e6c1f;
	hash[6] = 0x1f83d9abfb41bd6b;
	hash[7] = 0x5be0cd19137e2179;
	return (hash);
}

void			sha512_print(t_ullint *hash)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%.16zx", hash[i]);
		i++;
	}
	free(hash);
}

void			sha512(char *input, size_t len)
{
	t_ullint	size;
	t_uchar		*new_input;
	t_ullint	*res;
	t_ullint	*hash;

	size = sha512_define_size(len);
	new_input = sha512_align(size, input);
	res = sha512_init(NULL);
	hash = sha512_to_int(new_input, (ssize_t)size / 8, size);
	hash = sha512_len(len * 8, hash, (size / 8) - 1);
	hash = sha512_main_loop(size, hash, res);
	sha512_print(hash);
}
