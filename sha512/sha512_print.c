/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:29:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 17:22:40 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha512.h"

void		sha512_cont_print(t_gen *g)
{
	char	*tmp;

	tmp = unsigned_itoa_base(g->h03, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h04, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h05, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h06, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h07, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
}

void		sha512_prepare_print(char *std, t_gen *g)
{
	char	*tmp;

	if (sha512_main_loop(std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(g->h00, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h01, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(g->h02, 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	sha512_cont_print(g);
}
