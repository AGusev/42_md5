/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:23:36 by agusev            #+#    #+#             */
/*   Updated: 2019/04/16 15:18:11 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

const uint32_t g_r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16,
	23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15,
	21, 6, 10, 15, 21, 6, 10, 15, 21};

const uint32_t g_k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292564, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

int			md5_init(unsigned char *init_msg, size_t len, t_gen *g)
{
	g->h0 = 0x67452301;
	g->h1 = 0xefcdab89;
	g->h2 = 0x98badcfe;
	g->h3 = 0x10325476;
	g->length = len + 1;
	while (g->length % 64 != 56)
		g->length++;
	if (!(g->msg = malloc(g->length + 64)))
		return (-1);
	g->msg = ft_bzero(g->msg, g->length + 64);
	ft_strcpy((char*)g->msg, (const char *)init_msg);
	*(uint32_t*)(g->msg + len) = 0x80;
	*(uint32_t*)(g->msg + g->length) = (uint32_t)(8 * len);
	g->padded = 0;
	return (0);
}

void		md5_process(t_gen *g, int i)
{
	if (i < 16)
	{
		g->f = (g->b & g->c) | ((~g->b) & g->d);
		g->g = i;
	}
	else if (i < 32)
	{
		g->f = (g->d & g->b) | ((~g->d) & g->c);
		g->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		g->f = g->b ^ g->c ^ g->d;
		g->g = (3 * i + 5) % 16;
	}
	else
	{
		g->f = g->c ^ (g->b | (~g->d));
		g->g = (7 * i) % 16;
	}
	g->tmp = g->d;
	g->d = g->c;
	g->c = g->b;
	g->b = g->b + leftrotate((g->a + g->f + g_k[i] + g->w[g->g]), g_r[i]);
	g->a = g->tmp;
}

int			md5(unsigned char *init_msg, size_t len, t_gen *g)
{
	int i;

	if (md5_init(init_msg, len, g) == -1)
		return (-1);
	while (g->padded < g->length)
	{
		g->w = (uint32_t *)(g->msg + g->padded);
		g->a = g->h0;
		g->b = g->h1;
		g->c = g->h2;
		g->d = g->h3;
		i = -1;
		while (++i < 64)
			md5_process(g, i);
		g->h0 += g->a;
		g->h1 += g->b;
		g->h2 += g->c;
		g->h3 += g->d;
		g->padded += 64;
	}
	free(g->msg);
	return (0);
}
