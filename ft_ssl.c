/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:05:19 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 17:11:37 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		set_flags(t_gen *g, int flag, char *read)
{
	while (flag == 0)
	{
		write(1, "ssl> ", 200);
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
		sha512_prepare_print(read, g);
	return ;
}

void		rotate_file_not(t_gen *g, char **argv)
{
	if (!g->f_q)
	{
		if (ft_strcmp(argv[1], "sha224") == 0)
			ft_putstr("SHA224 (");
		else if (ft_strcmp(argv[1], "SHA256") == 0)
			ft_putstr("SHA256 (");
		else if (ft_strcmp(argv[1], "SHA256") == 0)
			ft_putstr("SHA512 (");
		else
			ft_putstr("MD5 (");
		ft_printf("%s) = ", argv[g->pars]);
	}
	if (ft_strcmp(argv[1], "sha224") == 0)
		sha224_prepare_print(g->stdin, g);
	else if (ft_strcmp(argv[1], "sha256") == 0)
		sha256_prepare_print(g->stdin, g);
	else if (ft_strcmp(argv[1], "sha512") == 0)
		sha512_prepare_print(g->stdin, g);
	else
		md5_print(g->stdin, g);
	ft_putchar('\n');
}

void		rotate_file(t_gen *g, char **argv)
{
	if (no_such_file(g, argv) == -1)
		return ;
	get_line(&g->stdin, g->fd);
	if (!g->f_r)
		rotate_file_not(g, argv);
	else
		extra(g, argv);
	free(g->stdin);
	close(g->fd);
	g->pars++;
}

void		md5_sha(t_gen *g, char **ac, int av)
{
	flag_parsing(g, av, ac);
	if (g->f_p || (!g->nb_file && !g->f_s))
	{
		get_line(&g->stdin, 0);
		if (g->f_p)
			ft_putstr(g->stdin);
		if (ft_strcmp(ac[1], "sha224") == 0)
			sha224_prepare_print(g->stdin, g);
		else if (ft_strcmp(ac[1], "sha256") == 0)
			sha256_prepare_print(g->stdin, g);
		else if (ft_strcmp(ac[1], "sha512") == 0)
			sha512_prepare_print(g->stdin, g);
		else
			md5_print(g->stdin, g);
		ft_putstr("\n");
		free(g->stdin);
	}
	g->pars = 2;
	while (g->pars < av)
		if (apply_flags(g, ac, av) == -1)
			break ;
	while (g->pars < av)
		rotate_file(g, ac);
}

int			main(int argc, char **argv)
 {
	t_gen	g;

// error : ft_ssl usage
	if (argc == 1)
	{
		ft_printf("usage: ssl command [command opts] [command args]\n");
		set_flags(&g, 0, NULL);
		return (0);
	}
	if (ft_strcmp(argv[1], "md5") == 0 || ft_strcmp(argv[1], "sha224") == 0
		|| ft_strcmp(argv[1], "sha256") == 0
		|| ft_strcmp(argv[1], "sha512") == 0)
		md5_sha(&g, argv, argc);
	else
	{
		ft_printf("ssl: Error: '%s' is an invalid command.\
		\n\nStandard commands:\
		\n\nMessage Digest commands:\nmd5\nsha224\nsha256\nsha512\n\nCipher\
		commands:\n", argv[1]);
	}

	return (0);
}
