/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:29:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 23:51:47 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha256.h"

void		sha256_print_cont(t_gen *g)
{
	char	*tmp;

	tmp = unsigned_itoa_base(g->h3, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h4, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h5, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h6, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h7, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		sha256_prepare_print(char *std, t_gen *g)
{
	char	*tmp;

	if (sha256_main_loop(std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(g->h0, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h1, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h2, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	sha256_print_cont(g);
}
