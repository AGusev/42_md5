/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:20:06 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:32:19 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atoi(const char *str)
{
	int		i;
	int		a;
	ssize_t	end;

	i = 0;
	a = 1;
	end = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		a = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		end = (end * 10) + (str[i++] - '0');
		if (end >= 9223372036854775807 && a == 1)
			return (-1);
		else if (end > 9223372036854775807 && a == -1)
			return (0);
	}
	return (end * a);
}