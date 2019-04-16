/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:29:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/15 18:14:21 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "sha512.h"

void		sha512_cont_print(t_gen *g)
{
	char	*temp;

	temp = unsigned_itoa_base_64(g->h03, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
 	temp = unsigned_itoa_base_64(g->h04, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
	temp = unsigned_itoa_base_64(g->h05, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
	temp = unsigned_itoa_base_64(g->h06, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
	temp = unsigned_itoa_base_64(g->h07, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
}

void		sha512_prepare_print(char *std, t_gen *g)
{
	char	*temp;

	if (sha512_main_loop(std, ft_strlen(std), g) == -1)
		return ;
	temp = unsigned_itoa_base_64(g->h00, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
	temp = unsigned_itoa_base_64(g->h01, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
	temp = unsigned_itoa_base_64(g->h02, 16);
	add_zero(temp);
	ft_putstr(temp);
	free(temp);
	sha512_cont_print(g);
}

