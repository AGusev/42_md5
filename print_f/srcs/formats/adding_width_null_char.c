/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_width_null_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:43:03 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:53:01 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char		*adding_width_null_char(t_flags *flags, char *answer, \
		int *length, char **str)
{
	char	*width;

	*length += ft_strlen(*str);
	write(1, *str, ft_strlen(*str));
	*str = ft_update(*str, ft_strnew(1));
	if (flags->width <= 1)
	{
		ft_putchar('\0');
		return (answer);
	}
	width = ft_bchar(flags->width - 1, ' ');
	*length += ft_strlen(width);
	if (flags->right_padding == 0)
	{
		write(1, width, ft_strlen(width));
		ft_putchar('\0');
	}
	else
	{
		ft_putchar('\0');
		write(1, width, ft_strlen(width));
	}
	free(width);
	return (answer);
}
