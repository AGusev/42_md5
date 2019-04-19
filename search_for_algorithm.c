/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_algorithm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:17 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:34:18 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int search_for_algorithm(t_algorithm *algorithm, t_flags *flags, char *argv)
{
	int i;

	i = 0;
	while (i < ALGORITHM_NUM)
	{
		if (!ft_strcmp(algorithm->name, argv))
		{
			flags->algo_name = ft_strdup(algorithm->name);
			if (i < HASH_NUM)
				flags->hash++;
			else if (i >= HASH_NUM && i < HASH_NUM + CIPHER_NUM)
				flags->cipher++;
			return (i);
		}
		algorithm = algorithm->next;
		i++;
	}
	return (-1);
}
