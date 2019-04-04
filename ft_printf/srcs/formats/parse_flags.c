/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:41:25 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:53:34 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int			parse_flags(char **format, t_flags *flags, va_list *arg)
{
	if ((handling_flags(format, flags)) == NULL)
		return (-1);
	if ((handling_width(format, flags, arg)) == NULL)
		return (-1);
	if ((handling_precision(format, flags, arg)) == NULL)
		return (-1);
	if ((handling_format(format, flags)) == NULL)
		return (-1);
	flags->conversion = (**format);
	if (!ft_strcmp(flags->format, "l") && (**format) == 'c')
		flags->conversion = 'C';
	if (!ft_strcmp(flags->format, "l") && (**format) == 's')
		flags->conversion = 'S';
	return (1);
}
