/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:35:37 by agusev            #+#    #+#             */
/*   Updated: 2019/04/15 18:25:41 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "md5.h"

// Computation of the hash of a message begins by preparing the message
int			md5_prepare_message(unsigned char *init_msg, size_t len, t_gen *g)
{
//The initial hash value H(0) is the following sequence of 32-bit words
	g->h0 = 0x67452301;
	g->h1 = 0xefcdab89;
	g->h2 = 0x98badcfe;
	g->h3 = 0x10325476;

// The length of the message M in bits
// Pre-processing: adding a single 1 bit
	g->length = len + 1;
// The length of the padded message should  be a multiple of 512 bit
// Process the message in successive 512-bit chunks
	while (g->length % 64 != 56)
		g->length++;
	if (!(g->msg = malloc(g->length + 64)))
		return (-1);
	g->msg = ft_bzero(g->msg, g->length + 64);
	ft_strcpy((char*)g->msg, (const char *)init_msg);
	*(uint32_t*)(g->msg + len) = 0x80;
	*(uint32_t*)(g->msg + g->length) = (uint32_t)(8 * len);
	g->padding = 0;
	return (0);
}

void		md5_algorithm(t_gen *g, int i)
{
//	Apply the MD5 compression function to update registers a, b, c, d.
//	( 0 ≤ i ≤ 15): F := D xor (B and (C xor D))
//	(16 ≤ i ≤ 31): F := C xor (D and (B xor C))
//
//		F(X,Y,Z) = (x & y) | (~x & z)
//		G(X,Y,Z) = (x & z) | (y & ~z)
//		H(X,Y,Z) = x ^ y ^ z
//		I(X,Y,Z) = y ^ (x | ~z)
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
	g->b = g->b + lor((g->a + g->f + g_k[i] + g->w[g->g]), g_r[i]);
	g->a = g->tmp;
}

int			md5_main_loop(unsigned char *init_msg, size_t len, t_gen *g)
{
	int i;
	if (md5_prepare_message(init_msg, len, g) == -1)
		return (-1);
	while (g->padding < g->length)
	{
// Initialize registers a; b; c; d; e; f ; g; h with the (i  1)st intermediate hash value
		g->w = (uint32_t*)(g->msg + g->padding);
		g->a = g->h0;
		g->b = g->h1;
		g->c = g->h2;
		g->d = g->h3;
		i = -1;
// Apply the MD5compression function
		while (++i < 64)
			md5_algorithm(g, i);
//  Compute the i^th intermediate hash value H^(i)
		g->h0 += g->a;
		g->h1 += g->b;
		g->h2 += g->c;
		g->h3 += g->d;
		g->padding += 64;
	}
	free(g->msg);
	return (0);
}

