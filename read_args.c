/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argvs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:49 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 01:47:07 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		if_flags(t_flags *flags, char *argv)
{
	if (flags->hash && !strcmp("-p", argv)) // hash
		flags->p++;
	else if (flags->hash && !strcmp("-s", argv))
		flags->s++;
	else if (flags->hash && !strcmp("-q", argv))
		flags->q++;
	else if (flags->hash && !strcmp("-r", argv))
		flags->r++;
	else if (flags->cipher && !strcmp("-d", argv)) // cipher
		flags->d++;
	else if (flags->cipher > 4 && !strcmp("-e", argv))
		flags->e++;
	else if (flags->cipher > 4 && !strcmp("-i", argv))
		flags->i++;
	else if (flags->cipher > 4 && !strcmp("-o", argv))
		flags->o++;
	else if (argv[0] == '-')
		return (0);
	else if (argv[0] != '-')
		return (-1);
	return (1);
}

int		check_file(char *name, t_flags *flags)
{
	int		fd;
	char	*file;

	fd = open(name, O_RDONLY);
	if (fd > 0)
	{
		flags->file++;
		file = fd_read(fd);
		search_for_func(file, flags);
		return (1);
	}
	else
		return (0);
}

int 	read_hash(t_flags *flags, char **argv, int *i)
{
	if ((ft_strcmp(argv[1], "md5") == 0 ||
	ft_strcmp(argv[1], "sha224") == 0 ||
	ft_strcmp(argv[1], "sha256") == 0||
	ft_strcmp(argv[1], "sha384") ==0 ||
	ft_strcmp(argv[1], "sha512") == 0) && argv[2] != '\0')
		ft_printf("%s(%s)= ", ft_strtoupper(argv[1]), argv[2]);
	if (!argv[*i])
		search_for_func(fd_read(0), flags);
	else if (((if_flags(flags, argv[*i])) == -1 || flags->file) && !check_file(argv[*i], flags))
		error_file(argv[*i], flags);
	else if (!flags->file && flags->s && argv[*i + 1])
	{
		++*i;
		search_for_func(fd_read(0), flags);
	}
	else if (!flags->file && flags->p)
		search_for_func(fd_read(0), flags);
	return (1);
}

int 	read_cipher(t_flags *flags)
{
	search_for_func(fd_read(0), flags);
	return (1);
}

void	read_input(t_flags *flags, t_algorithm *algorithm, int argvc, char **argv)
{
	int i;
	int first;

	first = 0;
	i = 1;
	if (argvc == 1)
	{
		argv = from_stdin(&argvc, flags);
		i = 0;
	}
	if ((flags->alg_index = search_for_algorithm(algorithm, flags, argv[i])) == -1)
	{
		error_algorithm(algorithm, argv[i]);
		return ;
	}
	i++;
	while (i < argvc || !first)
	{
		if (i < argvc && !if_flags(flags, argv[i]))
		{
			error_option(argv[i]);
			break ;
		}
		if (flags->hash)
			read_hash(flags, argv, &i);
		else if (flags->cipher)
			read_cipher(flags);
		i++;
		first++;
	}
	if (flags->stdin)
		ft_del_doublestr(&argv);
}
