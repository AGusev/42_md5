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

#include "../ssl.h"

void	free_flags(t_flags * flags)
{
	flags->p = 0;
	flags->s = 0;
	flags->r = 0;
	flags->q = 0;
}

void	hash_print(char *input, t_flags *flags, const t_alg *alg)
{
	if (flags->p)
	{
		if (flags->file)
			ft_printf("-------------> flag p file %s\n", alg);
		else if (!flags->file)
			ft_printf("--------------->flag p stdin %s\n", input);
	}
	else if (flags->s)
		ft_printf("flag s \n");
	if (flags->q)
		ft_printf("flag q \n");
	else if (flags->r)
		ft_printf("flag r \n");
/* 	if (flags->p){
		ft_printf("%s\n", input);
		ft_printf("<-------------------------> \n");
}
 	else if (!flags->q && flags->s && !flags->file && !flags->r)
	{
		ft_printf("SHA256 (%s) = \n", input);
		ft_print_upper(flags->algo_name);
		 ft_printf(" (%s) = ", input);
	}
	alg[flags->alg_index](input, ft_strlen(input));
 	if (!flags->q && flags->r && !flags->file && !flags->p)
		ft_printf(" %s = ", input);
 	else if (flags->q && !flags->file)
	{
		ft_printf(" %s", input);
	} */
	else
		ft_printf("\n");
	free_flags(flags);
}

void	search_for_func(char *input, t_flags *flags)
{
	const t_alg alg[algo_num] = {MD5, sha256, sha224, sha384, sha512};

	if (flags->hash)
		hash_print(input, flags, alg);
}


int		if_flags(t_flags *flags, char *argv)
{
	if (flags->hash && !strcmp("-p", argv))
		flags->p++;
	else if (flags->hash && !strcmp("-s", argv))
		flags->s++;
	else if (flags->hash && !strcmp("-q", argv))
		flags->q++;
	else if (flags->hash && !strcmp("-r", argv))
		flags->r++;
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
/*  	if ((ft_strcmp(argv[1], "md5") == 0 ||
	ft_strcmp(argv[1], "sha224") == 0 ||
	ft_strcmp(argv[1], "sha256") == 0||
	ft_strcmp(argv[1], "sha384") ==0 ||
	ft_strcmp(argv[1], "sha512") == 0) && argv[2] != '\0')
		ft_printf("%s(%s)= ", ft_strtoupper(argv[1]), argv[2]); */
	int fd;

	fd = open(argv[*i], O_RDONLY);
	if (!argv[*i])
		search_for_func(fd_read(fd), flags);
	else if (((if_flags(flags, argv[*i])) == -1 || flags->file) && !check_file(argv[*i], flags))
		error_file(argv[*i], flags);
	else if (!flags->file && flags->s && argv[*i])
	{
		 ++*i;
		 search_for_func(fd_read(fd), flags);
	}
	//
	//
	//error
	else if (!flags->file && flags->p && argv[*i]){
		search_for_func(fd_read(fd), flags);
	}
	else if (!flags->file && flags->r)
		search_for_func(fd_read(fd), flags);
	else if (!flags->file && flags->q)
		search_for_func(fd_read(fd), flags);
	else
		ft_printf("\n");
	return (1);
}

void	read_input(t_flags *flags, t_algorithm *algorithm, int argc, char **argv)
{
	int i;
	int first;

	first = 0;
	i = 1;
	if (argc == 1)
	{
		argv = from_stdin(&argc, flags);
		i = 0;
	}
	if ((flags->alg_index = search_for_algorithm(algorithm, flags, argv[i])) == -1)
	{
		error_algorithm(algorithm, argv[i]);
		return ;
	}
	i++;
	while (i < argc || !first)
	{
		if (i < argc && !if_flags(flags, argv[i]))
		{
			error_option(argv[i]);
			break ;
		}
		if (flags->hash)
		{

			read_hash(flags, argv, &i);
/* 			if (((ft_strcmp(argv[1], "md5") == 0 ||
				ft_strcmp(argv[1], "sha224") == 0 ||
				ft_strcmp(argv[1], "sha256") == 0||
				ft_strcmp(argv[1], "sha384") ==0 ||
				ft_strcmp(argv[1], "sha512") == 0) && argv[2] != '\0'))
					ft_printf("%s(%s)= ", ft_strtoupper(argv[1]), argv[2]); */
		}
		i++;
		first++;
	}
	if (flags->stdin)
		ft_del_doublestr(&argv);
}
