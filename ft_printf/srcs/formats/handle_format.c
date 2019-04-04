/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:44:39 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:52:49 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char		*handling_format(char **format, t_flags *flags)
{
	flags->format = ft_strnew(1);
	if ((**format) == 'l')
		flags->format = ft_update(flags->format, ft_strdup("l"));
	if ((**format) == 'h')
		flags->format = ft_update(flags->format, ft_strdup("h"));
	if ((**format) == 'j')
		flags->format = ft_update(flags->format, ft_strdup("j"));
	if ((**format) == 'z')
		flags->format = ft_update(flags->format, ft_strdup("z"));
	if ((**format) == 'z' || (**format) == 'j' || (**format) == 'l' || \
		(**format) == 'h')
		(*format)++;
	if ((**format) == 'h' && !ft_strcmp(flags->format, "h"))
		flags->format = ft_update(flags->format, ft_strdup("hh"));
	if ((**format) == 'l' && !ft_strcmp(flags->format, "l"))
		flags->format = ft_update(flags->format, ft_strdup("ll"));
	if (!ft_strcmp(flags->format, "ll") || !ft_strcmp(flags->format, "hh"))
		(*format)++;
	return (*format);
}
