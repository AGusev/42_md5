/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:18:29 by agusev            #+#    #+#             */
/*   Updated: 2019/04/15 13:25:43 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		flag_parsing(t_gen *g, int ac, char **av)
{
	g->i = 2;
	g->f_p = 0;
	g->f_q = 0;
	g->f_r = 0;
	g->f_s = 0;
	while (g->i < ac)
	{
		if (ft_strcmp("-p", av[g->i]) == 0)
			g->f_p = 1;
		else if (ft_strcmp("-q", av[g->i]) == 0)
			g->f_q = 1;
		else if (ft_strcmp("-r", av[g->i]) == 0)
			g->f_r = 1;
		else if (ft_strcmp("-s", av[g->i]) == 0)
		{
			g->i++;
			g->f_s++;
		}
		else
			break ;
		g->i++;
	}
	g->nb_file = g->i - ac;
}

void		no_rotation_print(t_gen *g, char **av)
{
	if (!g->f_q)
	{
		if (ft_strcmp(av[1], "sha256") == 0)
			ft_putstr("SHA256 (\"");
		else if (ft_strcmp(av[1], "sha224") == 0)
			ft_putstr("SHA224 (\"");
		else if (ft_strcmp(av[1], "sha512") == 0)
			ft_putstr("SHA512 (\"");
		else
			ft_putstr("MD5 (\"");
		ft_putstr(av[g->pars]);
		ft_putstr("\") = ");
	}
	if (ft_strcmp(av[1], "sha256") == 0)
		sha256_prepare_print(av[g->pars], g);
	else if (ft_strcmp(av[1], "sha224") == 0)
		sha224_prepare_print(av[g->pars], g);
	else if (ft_strcmp(av[1], "sha512") == 0)
		sha512_prepare_print(av[g->pars], g);
	else
		md5_print(av[g->pars], g);
	ft_putchar('\n');
}

void		rotation_print(t_gen *g, char **av)
{
	if (ft_strcmp(av[1], "sha256") == 0)
		sha256_prepare_print(av[g->pars], g);
	else if (ft_strcmp(av[1], "sha224") == 0)
		sha256_prepare_print(av[g->pars], g);
	else if (ft_strcmp(av[1], "sha512") == 0)
		sha512_prepare_print(av[g->pars], g);
	else
	{
		ft_printf("MD5 (\"%s\") = ", av[g->pars]);
		md5_print(av[g->pars], g);
	}
	if (!g->f_q)
		ft_printf(" \"%s\"\n", av[g->pars]);
	else
		ft_putstr("\n");
}

int			apply_flags(t_gen *g, int ac, char **av)
{
	if (ft_strcmp("-p", av[g->pars]) == 0)
		g->f_p = 1;
	else if (ft_strcmp("-q", av[g->pars]) == 0)
		g->f_q = 1;
	else if (ft_strcmp("-r", av[g->pars]) == 0)
		g->f_r = 1;
	else if (ft_strcmp("-s", av[g->pars]) == 0)
	{
		g->pars++;
		if (g->pars < ac)
		{
			if (!g->f_r)
				no_rotation_print(g, av);
			else
				rotation_print(g, av);
		}
	}
	else
		return (-1);
	g->pars++;
	return (0);
}

int			no_such_file(t_gen *g, char **av)
{
	if ((g->fd = open(av[g->pars], O_RDWR)) < 0)
	{
		if (ft_strcmp(av[1], "sha256") == 0)
			ft_putstr("ft_ssl: sha256: ");
		if (ft_strcmp(av[1], "sha224") == 0)
			ft_putstr("ft_ssl: sha224: ");
		if (ft_strcmp(av[1], "sha512") == 0)
			ft_putstr("ft_ssl: sha512: ");
		else
			ft_putstr("ft_ssl: md5: ");
		ft_putstr(av[g->pars]);
		ft_putstr(": No such file or directory\n");
		g->pars++;
		return (-1);
	}
	return (0);
}
