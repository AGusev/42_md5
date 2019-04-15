/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:05:19 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 23:38:53 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		rotate_file_not(t_gen *g, char **av)
{
	if (!g->f_q)
	{
		if (ft_strcmp(av[1], "sha224") == 0)
			ft_putstr("SHA224 (");
		else if (ft_strcmp(av[1], "SHA256") == 0)
			ft_putstr("SHA256 (");
		else if (ft_strcmp(av[1], "SHA512") == 0)
			ft_putstr("SHA512 (");
		else
			ft_putstr("MD5 (");
		ft_printf("%s) = ", av[g->pars]);
	}
	if (ft_strcmp(av[1], "sha224") == 0)
		sha224_prepare_print(g->stdin, g);
	else if (ft_strcmp(av[1], "sha256") == 0)
		sha256_prepare_print(g->stdin, g);
	else if (ft_strcmp(av[1], "sha512") == 0)
		sha256_prepare_print(g->stdin, g);
	else
		md5_print(g->stdin, g);
	ft_putchar('\n');
}

void		rotate_file(t_gen *g, char **av)
{
	if (no_such_file(g, av) == -1)
		return ;
	get_line(&g->stdin, g->fd);
	if (!g->f_r)
		rotate_file_not(g, av);
	else
		extra(g, av);
	free(g->stdin);
	close(g->fd);
	g->pars++;
}

void		start(t_gen *g, int ac, char **av)
{
	flag_parsing(g, ac, av);
	if (g->f_p || (!g->nb_file && !g->f_s))
	{
		get_line(&g->stdin, 0);
		if (g->f_p)
			ft_putstr(g->stdin);
		if (ft_strcmp(av[1], "sha224") == 0)
			sha224_prepare_print(g->stdin, g);
		else if (ft_strcmp(av[1], "sha256") == 0)
			sha256_prepare_print(g->stdin, g);
		else if (ft_strcmp(av[1], "sha512") == 0)
			sha256_prepare_print(g->stdin, g);
		else
			md5_print(g->stdin, g);
		ft_putstr("\n");
		free(g->stdin);
	}
	g->pars = 2;
	while (g->pars < ac)
		if (apply_flags(g, ac, av) == -1)
			break ;
	while (g->pars < ac)
		rotate_file(g, av);
}

int			main(int ac, char **av)
{
	t_gen	g;

	if (ac == 1)
	{
		ft_printf("usage: ssl command [command opts] [command args]\n");
		set_flags(&g, 0, NULL);
		return (0);
	}
	if (ft_strcmp(av[1], "md5") == 0
		|| ft_strcmp(av[1], "sha224") == 0
		|| ft_strcmp(av[1], "sha256") == 0
		|| ft_strcmp(av[1], "sha512") == 0)
		start(&g, ac, av);
	else
	{
		ft_printf("ssl: Error: '%s' is an invalid command.\
		\n\nStandard commands:\
		\n\nMessage Digest commands:\nmd5\nsha224\nsha256\nsha512\n\nCipher\
		commands:\n", av[1]);
	}
	return (0);
}
