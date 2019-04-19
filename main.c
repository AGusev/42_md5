/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:36 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 05:00:36 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		get_line(char **ptr)
{
	char	c[2];
	int		check;
	char	*str;
	char	*tmp;

	check = 2;
	c[1] = 0;
	str = ft_strdup("");
	while (check > 0)
	{
		check = read(0, c, 1);
		if (c[0] == 10)
			check = 0;
		if (check == 0)
			break ;
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	ptr[0] = str;
}

int main(int argc, char **argv)
{
	t_algorithm	*algorithm;
	t_flags	*flags;
	char	command[] = "md5 sha256 sha224 sha384 sha512 base_64";

	if (argc < 2)
	{
		write(1, "ft_ssl> ", 8);
		get_line(argv);
		if (ft_strcmp(argv[0], "quit") == 0)
			return -1;
	}
	algorithm = algorithm_create(command);
	flags = flags_struct();
	read_input(flags, algorithm, argc, argv);
	algorithm_delete(algorithm);
	flags_struct_del(flags);
//	system("leaks ft_ssl");
}
