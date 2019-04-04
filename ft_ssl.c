/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:52:47 by agusev            #+#    #+#             */
/*   Updated: 2019/04/03 23:09:49 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_strings	g_ss[100];
int			g_ss_cnt = 0;
int			g_exit_value = 0;

static t_cmd	*check_commands(char *command)
{
	int		i;

	i = 0;
	while (i < g_cmd_cnt)
	{
		if (ft_strcmp(command, g_commands[i].command) == 0)
			return (&g_commands[i]);
		i++;
	}
	return (NULL);
}

static size_t	process_params(t_cmd *cmd, int *cnt, char **av)
{
	size_t	result;

	result = check_params(cmd, cnt, av);
	if (result == 1)
	{
		if (cmd->exact_match_params == 1)
		{
// 				error(ft_ssprintf("%s: illegal option '%s'.\n",
// //			 	cmd->command, av[*cnt]), 0, 1);
			print_options_for_command(cmd);
		}
	}
	return (result);
}

int				main(int ac, char **av)
{
	t_cmd	*cmd;
	int		cnt;
	size_t	f;

	if (ac == 1)
		print_usage();
	if ((cmd = check_commands(av[1])) == NULL)
	{
//		error(ft_ssprintf("Error: '%s' is an invalid command.\n", av[1]), 0, 1);
		print_standard_commands();
	}
	cnt = ac - 2;
	f = 0;
	if (cnt != 0)
		f = process_params(cmd, &cnt, av + 2);
	(cmd->fn)(f, cnt, &av[ac - cnt]);
	return (g_exit_value);
}