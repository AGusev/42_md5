/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:42:11 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:46:06 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char			*conversion_d_i(va_list *arg, t_flags *flags)
{
	char		*answer;
	intmax_t	tmp;

	tmp = va_arg(*arg, intmax_t);
	if (!ft_strcmp(flags->format, "ll"))
		tmp = (long long)tmp;
	else if (!ft_strcmp(flags->format, "l"))
		tmp = (long int)tmp;
	else if (!ft_strcmp(flags->format, "hh"))
		tmp = (char)tmp;
	else if (!ft_strcmp(flags->format, "h"))
		tmp = (short int)tmp;
	else if (!ft_strcmp(flags->format, "j"))
		tmp = (intmax_t)tmp;
	else if (!ft_strcmp(flags->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (int)tmp;
	answer = ft_itoa_intmax(tmp);
	if (answer[0] == '-')
	{
		flags->minus = 1;
		answer = ft_update(answer, ft_strsub(answer, 1, ft_strlen(answer) - 1));
	}
	return (answer);
}
