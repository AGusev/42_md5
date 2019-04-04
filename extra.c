/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:21:42 by agusev            #+#    #+#             */
/*   Updated: 2019/04/03 23:21:53 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	extra(t_gen *g, char **argv)
{
	if (ft_strcmp(argv[1], "sha256") == 0)
		go_sha256(g->stdin, g);
	else if (ft_strcmp(argv[1], "sha224") == 0)
		go_sha224(g->stdin, g);
	else
		go_md5(g->stdin, g);
	if (!g->f_q)
		printf(" %s\n", argv[g->pars]);
	else
		ft_printf("\n");
}
