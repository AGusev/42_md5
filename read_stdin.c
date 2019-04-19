/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:32 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 00:17:27 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		search_for_argc(char **argv)
{
	int size;

	size = 0;
	while (argv && argv[size])
		size++;
	return (size);
}

char	**from_stdin(int *argc, t_flags *flags)
{
	char **argv;
	char *input;

	input = fd_read(0);
	argv = split_into_array(input, ' ');
	*argc = search_for_argc(argv);
	flags->stdin++;
	if (!*argc)
		error_usage();
	return (argv);
}
