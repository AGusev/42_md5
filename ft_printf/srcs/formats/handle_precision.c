/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:44:47 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:53:31 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ft_star_precision(int *star_precision, va_list *arg, \
								t_flags *flags)
{
	int		precision;

	*star_precision = -1;
	precision = va_arg(*arg, int);
	flags->precision = precision;
}

char		*handling_precision(char **format, t_flags *flags, va_list *arg)
{
	int		star_precision;

	star_precision = 0;
	if (**format == '.')
		while (**format == '.' || **format == '*' || ft_isdigit(**format))
		{
			flags->precision_exist = 1;
			if (star_precision == 1 && ft_isdigit(**format))
				return (NULL);
			if (star_precision != 0 && **format == '*')
				return (NULL);
			if (**format == '*')
				ft_star_precision(&star_precision, arg, flags);
			if (ft_isdigit(**format))
			{
				star_precision = -1;
				flags->precision = flags->precision * 10 + **format - 48;
			}
			(*format)++;
		}
	return (*format);
}
