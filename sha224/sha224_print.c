/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:29:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 15:53:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha224.h"

void		sha224_print(t_gen *g)
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
}

void		sha224_prepare_print(char *std, t_gen *g)
{
	char	*tmp;

	if (sha224_main_loop(std, ft_strlen(std), g) == -1)
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
	sha224_print(g);
}
