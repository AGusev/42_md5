/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:35:37 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 17:04:26 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha512.h"

// Computation of the hash of a message begins by preparing the message
int			sha512_prepare_message(char *init_mg, size_t len, t_gen *g)
{
	int i;

//The initial hash value H(0) is the following sequence of 32-bit words
	g->h00 = 0x6a09e667f3bcc908ULL;
	g->h01 = 0xbb67ae8584caa73bULL;
	g->h02 = 0x3c6ef372fe94f82bULL;
	g->h03 = 0xa54ff53a5f1d36f1ULL;
	g->h04 = 0x510e527fade682d1ULL;
	g->h05 = 0x9b05688c2b3e6c1fULL;
	g->h06 = 0x1f83d9abfb41bd6bULL;
	g->h07 = 0x5be0cd19137e2179ULL;
//
// The length of the message M in bits
	g->length = len * 8;
// Append the bit \1" to the end of the message
// The length of the padded message should now be a multiple of 1024 bit
	g->offset = ((g->length + 16 + 64) / 512) + 1;
	if (!(g->msg_32 = malloc(16 * g->offset * 4)))
		return (-1);
	ft_bzero(g->msg_32, 16 * g->offset * 4);
	ft_memcpy((char *)g->msg_32, init_mg, ft_strlen(init_mg));
	((char*)g->msg_32)[ft_strlen(init_mg)] = 0x80;
// Parse the message into N 1024-bit blocks M(1), M(2) ... M(N)
	i = 0;
	while (i < (g->offset * 16) - 1)
	{
		g->msg_32[i] = revers_uint32(g->msg_32[i]);
		i++;
	}
	g->msg_32[((g->offset * 512 - 64) / 32) + 1] = g->length;
	return (0);
}

void		sha512_message_schedule(t_gen *g, int i)
{
	int j;

	g->w = malloc(512);
	ft_bzero(g->w, 512);
	ft_memcpy(g->w, &g->msg_32[i * 16], 16 * 32);
	j = 16;
	// Expanded message blocks W0; W1, ... W63 are computed as follows via the SHA-512 message schedule
	// For j = 16 to 79
	while (j < 79)
	{
		g->tmp4 = ror(g->w[j - 15], 7) ^
		ror(g->w[j - 15], 18) ^ (g->w[j - 15] >> 3);
		g->tmp = ror(g->w[j - 2], 17) ^
		ror(g->w[j - 2], 19) ^ (g->w[j - 2] >> 10);
		g->w[j] = g->w[j - 16] + g->tmp4 + g->w[j - 7] + g->tmp;
		j++;
	}
/*
Six logical functions are used in SHA-512. Each of these functions operates on
32-bit words and produces a 32-bit word as output. Each function is dened as
follows:
1			CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
2			MA(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
3			E0(x) (ROR(x, 2) ^ ROR(x, 13) ^ ROR(x, 22))
4			E1(x) (ROR(x, 6) ^ ROR(x, 11) ^ ROR(x, 25))
5			SI0(x) (ROR(x, 7) ^ ROR(x, 18) ^ ((x) >> 3))
6			SI1(x) (ROR(x, 17) ^ ROR(x, 19) ^ ((x) >> 10))
*/
	g->a = g->h00;
	g->b = g->h01;
	g->c = g->h02;
	g->d = g->h03;
	g->e = g->h04;
	g->f = g->h05;
	g->g = g->h06;
	g->h = g->h07;
}

void		sha512_algorithm(t_gen *g, int j)
{
// Apply the SHA-512 compression function to update registers a, b, ... h.
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

int			sha512_main_loop(char *init_mg, size_t len, t_gen *g)
{
	int i;
	int j;

// The hash computation proceeds as follows
	sha512_prepare_message(init_mg, len, g);
// For i = 1 to N (N = number of blocks in the padded message)
	i = 0;
	while (i < g->offset)
	{
// Initialize registers a; b; c; d; e; f ; g; h with the (i  1)st intermediate hash value
		sha512_message_schedule(g, i);
		j = -1;
// Apply the SHA-512 compression function
		while (++j < 80)
			sha512_algorithm(g, j);
//  Compute the i^th intermediate hash value H^(i)
		g->h00 += g->a;
		g->h01 += g->b;
		g->h02 += g->c;
		g->h03 += g->d;
		g->h04 += g->e;
		g->h05 += g->f;
		g->h06 += g->g;
		g->h07 += g->h;
		free(g->w);
		i++;
	}
	free(g->msg_32);
	return (0);
}
