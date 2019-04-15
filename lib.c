/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:21:26 by agusev            #+#    #+#             */
/*   Updated: 2019/04/14 22:50:02 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char		*add_zero(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i < 8)
	{
		ft_putchar('0');
		i++;
	}
	return (str);
}

void		get_new_line(char **ptr)
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

void		get_line(char **ptr, int fd)
{
	char	c[2];
	int		check;
	char	*str;
	char	*tmp;

	c[1] = 0;
	check = 2;
	str = ft_strdup("");
	while (check > 0)
	{
		check = read(fd, c, 1);
		if (check == 0)
		{
			break ;
		}
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	ptr[0] = str;
}
