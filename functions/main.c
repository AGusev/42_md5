/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:36 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 16:18:03 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

int					main(int argc, char **argv)
{

	t_algorithm	*algorithm;
	t_flags	*flags;
	char	command[] = "md5 sha256 sha224 sha384 sha512";
	algorithm = algorithm_create(command);
	flags = flags_struct();
	read_input(flags, algorithm, argc, argv);
	algorithm_delete(algorithm);
	flags_struct_del(flags);
//	system("leaks ft_ssl");
}
