/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:29:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 17:35:11 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

// right rotation by n bits
uint32_t	ror(uint32_t x, uint32_t n)
{
	return ((((unsigned int)x >> n)) | (x << (32 - n)));
}

void		extra(t_gen *g, char **argv)
{
	if (ft_strcmp(argv[1], "sha256") == 0)
		sha256_prepare_print(g->stdin, g);
	else if (ft_strcmp(argv[1], "sha256") == 0)
		sha256_prepare_print(g->stdin, g);
	else
		md5_print(g->stdin, g);
	if (!g->f_q)
		ft_printf(" %s\n", argv[g->pars]);
	else
		ft_printf("\n");
}

// input error message
void		error(char *read)
{
	ft_printf("ssl: Error: '%s' is an invalid command.\
	\n\nStandard commands:\
	\n\nMessage Digest commands:\nmd5\nsha224\nsha256\nsha512\n\nCipher\
	commands:\n", read);
}
