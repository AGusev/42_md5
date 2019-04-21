/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmStruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:33:57 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:38:07 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_algorithm	*algorithm_create(char *command)
{
	t_algorithm	*algorithm;
	t_algorithm	*alg;
	char 	**cmd_cpy;
	int		i;

	algorithm = (t_algorithm*)(malloc(sizeof(t_algorithm)));
	alg = algorithm;
	cmd_cpy = ft_strsplit(command, ' ');
	i = 0;
	while (i < algo_num)
	{
		algorithm->name = cmd_cpy[i];
		i++;
		if (i == algo_num)
			algorithm->next = NULL;
		else
			algorithm->next = (t_algorithm*)(malloc(sizeof(t_algorithm)));
		algorithm = algorithm->next;
	}
	free(cmd_cpy);
	return (alg);
}

void	algorithm_delete(t_algorithm *algorithm)
{
	t_algorithm *alg;

	alg = algorithm;
	while (alg)
	{
		alg = algorithm->next;
		ft_strdel(&algorithm->name);
		free(algorithm);
		algorithm = alg;
	}
}
