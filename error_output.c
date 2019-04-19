/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:35:11 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 02:44:48 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	error_algorithm(t_algorithm *algorithm, char *argv)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", argv);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\n");
	while (algorithm)
	{
		ft_printf("%s\n", algorithm->name);
		algorithm = algorithm->next;
	}
	ft_printf("\nCipher commands:\n");
}

void	error_option(char *argv)
{
	ft_printf("unknown option '%s'\noptions are\n", argv);
	ft_printf("-p   echo STDIN to STDOUT ");
	ft_printf("and append the checksum to STDOUT\n");
	ft_printf("-r   reverse the format of the output\n");
	ft_printf("-q   quiet mode\n");
	ft_printf("-s   print the sum of the given string\n");
}

void	error_file(char *argv, t_flags *flags)
{
	ft_printf("ft_ssl: ");
	ft_printf("%s: ", flags->algo_name);
	ft_printf("%s: ", argv);
	ft_printf("No such file or directory\n");
}

void	error_usage()
{
	ft_printf("usage: ft_ssl command [command opts] [command argvs]\n");
}
