/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:22:38 by agusev            #+#    #+#             */
/*   Updated: 2019/04/15 18:24:11 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

// right rotation by n bits
uint32_t	ror(uint32_t x, uint32_t n)
{
	return ((((unsigned int)x >> n)) | (x << (32 - n)));
}

uint64_t	ror_64(uint64_t x, uint8_t n)
{
	return ((((unsigned int)x >> n)) | (x << (64 - n)));
}

// left rotation by n bits
uint32_t	lor(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

// reverse by n bits
uint32_t	revers_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
		((n & 0xff00) << 8) | (n << 24));
}

uint64_t	revers_uint64(uint64_t n)
{
	return ((n & 0xff00000000000000) >> 56 \
			| (n & 0x00ff000000000000) >> 40 \
			| (n & 0x0000ff0000000000) >> 24 \
			| (n & 0x000000ff00000000) >> 8 \
			| (n & 0x00000000ff000000) << 8 \
			| (n & 0x0000000000ff0000) << 24 \
			| (n & 0x000000000000ff00) << 40 \
			| (n & 0x00000000000000ff) << 56);
}

