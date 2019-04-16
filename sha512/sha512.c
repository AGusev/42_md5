/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:35:37 by agusev            #+#    #+#             */
/*   Updated: 2019/04/15 18:25:43 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha512.h"

// Computation of the hash of a message begins by preparing the message
int			sha512_prepare_message(char *init_msg, size_t len, t_gen *g)
{
	int i;

//The initial hash value H(0) is the following sequence of 64-bit words
	g->h00 = 0x6a09e667f3bcc908ULL;
	g->h01 = 0xbb67ae8584caa73bULL;
	g->h02 = 0x3c6ef372fe94f82bULL;
	g->h03 = 0xa54ff53a5f1d36f1ULL;
	g->h04 = 0x510e527fade682d1ULL;
	g->h05 = 0x9b05688c2b3e6c1fULL;
	g->h06 = 0x1f83d9abfb41bd6bULL;
	g->h07 = 0x5be0cd19137e2179ULL;
// The length of the message M in bits
	g->length = len * 8;
// Append the bit \1" to the end of the message
// The length of the padded message should now be a multiple of 1024 bit
	g->padding = ((g->length + 16 + 128) / 1024) + 1;
	if (!(g->msg_64 = malloc(32 * g->padding * 4)))
		return (-1);
	ft_bzero(g->msg_64, 32 * g->padding * 4);
	ft_memcpy((char *)g->msg_64, init_msg, ft_strlen(init_msg));
	((char*)g->msg_64)[ft_strlen(init_msg)] = 0x80;
// Parse the message into N 1024-bit blocks M(1), M(2) ... M(N)
	i = 0;
	while (i < (g->padding * 16) - 1)
	{
		g->msg_64[i] = revers_uint64(g->msg_64[i]);
		i++;
	}
	g->msg_64[((g->padding * 1024 - 128) / 32) + 1] = g->length;
	return (0);
}

void		sha512_message_schedule(t_gen *g, int i)
{
	int j;

	g->ww = malloc(1024);
	ft_bzero(g->ww, 1024);
	ft_memcpy(g->ww, &g->msg_64[i * 16], 16 * 128);
	j = 16;
	// Expanded message blocks W0; W1, ... W63 are computed as follows via the SHA-512 message schedule
	// For j = 16 to 79
	// Wj <- SI(W[j-2]) + W[j - 7] + SI0(W[j-15]) + W[j - 16]
	while (j < 80)
	{
		// g->temp4 = ror_64(g->ww[j - 15], 1) ^ ror_64(g->ww[j - 15], 8) ^ (g->ww[j - 15] >> 7);
		// g->temp = ror_64(g->ww[j - 2], 19) ^ ror_64(g->ww[j - 2], 61) ^ (g->ww[j - 2] >> 6);
		g->ww[j] = g->ww[j - 16]
		+ ror_64(g->ww[j - 15], 1) ^ ror_64(g->ww[j - 15], 8) ^ (g->ww[j - 15] >> 7)
		+ g->ww[j - 7]
		+ ror_64(g->ww[j - 2], 19) ^ ror_64(g->ww[j - 2], 61) ^ (g->ww[j - 2] >> 6);
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
	g->temp3 = g->hh + g->temp + g->temp2 + g_k[j] + g->ww[j];
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
	while (i < g->padding)
	{
// Initialize registers a; b; c; d; e; f ; g; h with the (i  1)st intermediate hash value
		sha512_message_schedule(g, i);
		j = -1;
// Apply the SHA-512 compression function
		while (++j < 79)
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
		free(g->ww);
		i++;
	}
	free(g->msg_64);
	return (0);
}
