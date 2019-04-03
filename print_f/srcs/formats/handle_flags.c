/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:41:34 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:52:52 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char		*handling_flags(char **format, t_flags *flags)
{
	while (**format == '#' || **format == ' ' || **format == '+' || \
			**format == '-' || **format == '0')
	{
		if (**format == '#')
			flags->hashtag = 1;
		if (**format == '-')
			flags->right_padding = 1;
		if (**format == ' ')
			flags->space = 1;
		if (**format == '+')
			flags->plus = 1;
		if (**format == '0')
			flags->zero_padding = 1;
		if (flags->right_padding == 1)
			flags->zero_padding = 0;
		(*format)++;
	}
	return (*format);
}
