/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:40 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 21:46:04 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

void		md5_algorithm(t_md *hash, ssize_t size, t_uint *arr)
{
	int i;
	int x;
	int j;
	int k;

	x = 0;
	j = 0;
	k = 0;
	while (j < size)
	{
		i = 0;
		equal(hash);
		while (i < 64)
		{
			md5_transform(&i, &x, hash, arr + k);
			hash = hash->next->next->next;
			x = i == 16 ? 1 : x;
			x = i == 32 ? 5 : x;
			x = i == 48 ? 0 : x;
		}
		h0_plus_a(hash);
		j += 64;
		k += 16;
	}
	free(arr);
}

void		md5_init(t_md *lst)
{
	t_md	*hash;
	t_md	*head;

	head = lst;
	lst->a = 0x67452301;
	hash = md5_struct();
	lst->next = hash;
	lst = lst->next;
	lst->a = 0xEFCDAB89;
	hash = md5_struct();
	lst->next = hash;
	lst = lst->next;
	lst->a = 0x98BADCFE;
	hash = md5_struct();
	lst->next = hash;
	lst = lst->next;
	lst->a = 0x10325476;
	lst->next = head;
}

t_uint		*md5_shift(ssize_t len, t_uint *data, ssize_t i)
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
		i++;
	}
	return (data);
}

void		md5_print(t_md *hash)
{
	int				i;
	unsigned char	*tmp;
	t_md			*head;

	i = 0;
	head = hash;
	while (i < 4)
	{
		tmp = (unsigned char *)&hash->a;
		ft_printf("%.2x%.2x%.2x%.2x", tmp[0], tmp[1], tmp[2], tmp[3]);
		hash = hash->next;
		i++;
	}
	md5_del_struct(head);
}

void		MD5(char *input, size_t len)
{
	ssize_t	size;
	t_uchar	*new_input;
	t_uint	*arr;
	t_md	*hash;

	size = define_size(len);
	new_input = align(size, input);
	hash = md5_struct();
	md5_init(hash);
	arr = md5_length(new_input, size / 4, size);
	arr = md5_shift((len * 8), arr, ((size / 4) - 2));
	md5_algorithm(hash, size, arr);
	md5_print(hash);
}
