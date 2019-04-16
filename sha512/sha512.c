/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:35:37 by agusev            #+#    #+#             */
/*   Updated: 2019/04/15 17:17:02 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha512.h"

// Computation of the hash of a message begins by preparing the message
int			sha512_prepare_message(char *init_msg, size_t len, t_gen *g)
{
	int i;

//The initial hash value H(0) is the following sequence of 64-bit words
	g->h00 = 0x6a09e667f3bcc908;
	g->h01 = 0xbb67ae8584caa73b;
	g->h02 = 0x3c6ef372fe94f82b;
	g->h03 = 0xa54ff53a5f1d36f1;
	g->h04 = 0x510e527fade682d1;
	g->h05 = 0x9b05688c2b3e6c1f;
	g->h06 = 0x1f83d9abfb41bd6b;
	g->h07 = 0x5be0cd19137e2179;
// The length of the message M in bits
	g->length = len * 8;
// Append the bit \1" to the end of the message
// The length of the padded message should now be a multiple of 1024 bit
	g->offset = ((g->length + 16 + 64) / 512) + 1;
	if (!(g->msg_32 = malloc(16 * g->offset * 4)))
		return (-1);
	ft_bzero(g->msg_32, 16 * g->offset * 4);
	ft_memcpy((char *)g->msg_32, init_msg, ft_strlen(init_msg));
	((char*)g->msg_32)[ft_strlen(init_msg)] = 0x80;
// Parse the message into N 1024-bit blocks M(1), M(2) ... M(N)
	i = 0;
	while (i < (g->offset * 16) - 1)
	{
		g->msg_32[i] = revers_uint64(g->msg_32[i]);
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
	while (j < 63)
	{
		g->temp4 = ror_64(g->w[j - 15], 1) ^
		ror_64(g->w[j - 15], 8) ^ (g->w[j - 15] >> 7);
		g->temp = ror_64(g->w[j - 2], 19) ^
		ror_64(g->w[j - 2], 61) ^ (g->w[j - 2] >> 6);
		g->w[j] = g->w[j - 16] + g->temp4 + g->w[j - 7] + g->temp;
		j++;
	}
/*
Six logical functions are used in SHA-512. Each of these functions operates on
64-bit words and produces a 64-bit word as output. Each function is dened as
follows:
1			CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
2			MA(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
3			E0(x) (ROR(x, 28) ^ ROR(x, 34) ^ ROR(x, 39))
4			E1(x) (ROR(x, 14) ^ ROR(x, 18) ^ ROR(x, 41))
5			SI0(x) (ROR(x, 1) ^ ROR(x, 8) ^ ((x) >> 7))
6			SI1(x) (ROR(x, 19) ^ ROR(x, 61) ^ ((x) >> 6))
*/
	g->aa = g->h00;
	g->bb = g->h01;
	g->cc = g->h02;
	g->dd = g->h03;
	g->ee = g->h04;
	g->ff = g->h05;
	g->gg = g->h06;
	g->hh = g->h07;
}

void		sha512_algorithm(t_gen *g, int j)
{
// Apply the SHA-512 compression function to update registers a, b, ... h.
// Compute Ch(e,f,g), Maj(a,b,c), SI0(a), SI1(e), and Wj (see above)
	g->temp = ror_64(g->ee, 14) ^ ror_64(g->ee, 18) ^ ror_64(g->ee, 41);
	g->temp2 = (g->ee & g->ff) ^ ((~g->ee) & g->gg);
	g->temp3 = g->hh + g->temp + g->temp2 + g_k[j] + g->w[j];
	g->temp4 = ror_64(g->aa, 28) ^ ror_64(g->aa, 34) ^ ror_64(g->aa, 39);
	g->temp5 = (g->aa & g->bb) ^ (g->aa & g->cc) ^ (g->bb & g->cc);
	g->temp6 = g->temp4 + g->temp5;
	g->hh = g->gg;
	g->gg = g->ff;
	g->ff = g->ee;
	g->ee = g->dd + g->temp3;//d + T1
	g->dd = g->cc;
	g->cc = g->bb;
	g->bb = g->aa;
	g->aa = g->temp3 + g->temp6;//T1 + T2
}

int			sha512_main_loop(char *init_msg, size_t len, t_gen *g)
{
	int i;
	int j;

// The hash computation proceeds as follows
	sha512_prepare_message(init_msg, len, g);
// For i = 1 to N (N = number of blocks in the padded message)
	i = 0;
	while (i < g->offset)
	{
// Initialize registers a; b; c; d; e; f ; g; h with the (i  1)st intermediate hash value
		sha512_message_schedule(g, i);
		j = -1;
// Apply the SHA-512 compression function
		while (++j < 64)
			sha512_algorithm(g, j);
//  Compute the i^th intermediate hash value H^(i)
		g->h00 += g->aa;
		g->h01 += g->bb;
		g->h02 += g->cc;
		g->h03 += g->dd;
		g->h04 += g->ee;
		g->h05 += g->ff;
		g->h06 += g->gg;
		g->h07 += g->hh;
		free(g->w);
		i++;
	}
	free(g->msg_32);
	return (0);
}
