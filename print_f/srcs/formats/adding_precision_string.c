/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_precision_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:42:47 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:53:08 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char			*adding_precision_string(t_flags *flags, char *str)
{
	char		*tmp;

	tmp = ft_strdup(str);
	if (flags->conversion != 'S' && flags->conversion != 's')
		return (tmp);
	if (flags->precision == 0)
	{
		tmp = ft_strnew(1);
		return (tmp);
	}
	if (flags->precision >= (int)ft_strlen(str))
		return (tmp);
	tmp = ft_update(tmp, ft_strsub(str, 0, flags->precision));
	return (tmp);
}
