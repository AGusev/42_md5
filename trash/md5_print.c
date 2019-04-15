/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_print                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:29:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 15:13:38 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"
#include "md5.h"

void		md5_print(char *std, t_gen *g)
{
	char	*tmp;

	if (md5((uint8_t *)std, ft_strlen(std), g) == -1)
		return ;
	tmp = unsigned_itoa_base(revers_uint32(g->h0), 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h1), 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h2), 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
	tmp = unsigned_itoa_base(revers_uint32(g->h3), 16);
	add_zero(tmp);
	ft_putstr(tmp);
	free(tmp);
}
