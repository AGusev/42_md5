/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:35:37 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 22:32:04 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha224.h"

// Computation of the hash of a message begins by preparing the message
int			sha224_prepare_message(char *init_msg, size_t len, t_gen *g)
{
	int i;

//The initial hash value H(0) is the following sequence of 32-bit words
	g->h0 = 0xc1059ed8;
	g->h1 = 0x367cd507;
	g->h2 = 0x3070dd17;
	g->h3 = 0xf70e5939;
	g->h4 = 0xffc00b31;
	g->h5 = 0x68581511;
	g->h6 = 0x64f98fa7;
	g->h7 = 0xbefa4fa4;
//
// The length of the message M in bits
	g->length = len * 8;
// Append the bit \1" to the end of the message
// The length of the padded message should now be a multiple of 512 bit
	g->offset = 1 + ((g->length + 16 + 64) / 512);
	if (!(g->msg_32 = malloc(16 * g->offset * 4)))
		return (-1);
	ft_bzero(g->msg_32, 16 * g->offset * 4);
	ft_memcpy((char *)g->msg_32, init_msg, ft_strlen(init_msg));
	((char*)g->msg_32)[ft_strlen(init_msg)] = 0x80;
// Parse the message into N 512-bit blocks M(1), M(2) ... M(N)
	i = 0;
	while (i < (g->offset * 16) - 1)
	{
		g->msg_32[i] = revers_uint32(g->msg_32[i]);
		i++;
	}
	g->msg_32[((g->offset * 512 - 64) / 32) + 1] = g->length;
	return (0);
}

void		sha224_message_schedule(t_gen *g, int i)
{
	int j;

	g->w = malloc(512);
	ft_bzero(g->w, 512);
	ft_memcpy(g->w, &g->msg_32[i * 16], 16 * 32);
	j = 16;
	// Expanded message blocks W0; W1, ... W63 are computed as follows via the SHA-256 message schedule
	// For j = 16 to 63
	while (j < 64)
	{
		g->tmp4 = ror(g->w[j - 15], 7) ^
		ror(g->w[j - 15], 18) ^ (g->w[j - 15] >> 3);
		g->tmp = ror(g->w[j - 2], 17) ^
		ror(g->w[j - 2], 19) ^ (g->w[j - 2] >> 10);
		g->w[j] = g->w[j - 16] + g->tmp4 + g->w[j - 7] + g->tmp;
		j++;
	}
/*
Six logical functions are used in SHA-256. Each of these functions operates on
32-bit words and produces a 32-bit word as output. Each function is dened as
follows:
1			CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
2			MA(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
3			E0(x) (ROR(x, 2) ^ ROR(x, 13) ^ ROR(x, 22))
4			E1(x) (ROR(x, 6) ^ ROR(x, 11) ^ ROR(x, 25))
5			SI0(x) (ROR(x, 7) ^ ROR(x, 18) ^ ((x) >> 3))
6			SI1(x) (ROR(x, 17) ^ ROR(x, 19) ^ ((x) >> 10))
*/
	g->a = g->h0;
	g->b = g->h1;
	g->c = g->h2;
	g->d = g->h3;
	g->e = g->h4;
	g->f = g->h5;
	g->g = g->h6;
	g->h = g->h7;
}

void		sha224_algorithm(t_gen *g, int j)
{
// Apply the SHA-256 compression function to update registers a, b, ... h.
// Compute Ch(e,f,g), Maj(a,b,c), SI0(a), SI1(e), and Wj (see above)
	g->tmp = ror(g->e, 6) ^ ror(g->e, 11) ^ ror(g->e, 25);
	g->tmp2 = (g->e & g->f) ^ ((~g->e) & g->g);
	g->tmp3 = g->h + g->tmp + g->tmp2 + g_k[j] + g->w[j];
	g->tmp4 = ror(g->a, 2) ^ ror(g->a, 13) ^ ror(g->a, 22);
	g->tmp5 = (g->a & g->b) ^ (g->a & g->c) ^ (g->b & g->c);
	g->tmp6 = g->tmp4 + g->tmp5;
	g->h = g->g;
	g->g = g->f;
	g->f = g->e;
	g->e = g->d + g->tmp3;//d + T1
	g->d = g->c;
	g->c = g->b;
	g->b = g->a;
	g->a = g->tmp3 + g->tmp6;//T1 + T2
}

int			sha224_main_loop(char *init_msg, size_t len, t_gen *g)
{
	int i;
	int j;

// The hash computation proceeds as follows
	sha224_prepare_message(init_msg, len, g);
// For i = 1 to N (N = number of blocks in the padded message)
	i = 0;
	while (i < g->offset)
	{
// Initialize registers a; b; c; d; e; f ; g; h with the (i  1)st intermediate hash value
		sha224_message_schedule(g, i);
		j = -1;
// Apply the SHA-256 compression function
		while (++j < 64)
			sha224_algorithm(g, j);
//  Compute the i^th intermediate hash value H^(i)
		g->h0 += g->a;
		g->h1 += g->b;
		g->h2 += g->c;
		g->h3 += g->d;
		g->h4 += g->e;
		g->h5 += g->f;
		g->h6 += g->g;
		g->h7 += g->h;
		free(g->w);
		i++;
	}
	free(g->msg_32);
	return (0);
}
