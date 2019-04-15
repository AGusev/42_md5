/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:29:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 23:45:05 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		extra(t_gen *g, char **av)
{
	if (ft_strcmp(av[1], "sha224") == 0)
		sha224_prepare_print(g->stdin, g);
	else if (ft_strcmp(av[1], "sha256") == 0)
		sha256_prepare_print(g->stdin, g);
	else if (ft_strcmp(av[1], "sha512") == 0)
		sha256_prepare_print(g->stdin, g);
	else
		md5_print(g->stdin, g);
	if (!g->f_q)
		ft_printf(" %s\n", av[g->pars]);
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

void		set_flags(t_gen *g, int flag, char *read)
{
	while (flag == 0)
	{
		write(1, "ft_ssl> ", 8);
		get_new_line(&read);
		if (ft_strcmp(read, "md5") == 0)
			flag = 1;
		else if (ft_strcmp(read, "sha224") == 0)
			flag = 2;
		else if (ft_strcmp(read, "sha256") == 0)
			flag = 3;
		else if (ft_strcmp(read, "sha512") == 0)
			flag = 4;
		else if (ft_strcmp(read, "quit") == 0)
			return ;
		else
			error(read);
		free(read);
	}
	get_line(&read, 0);
	if (flag == 1)
		md5_print(read, g);
	else if (flag == 2)
		sha224_prepare_print(read, g);
	else if (flag == 3)
		sha256_prepare_print(read, g);
	else if (flag == 4)
		sha256_prepare_print(read, g);
	return ;
}
