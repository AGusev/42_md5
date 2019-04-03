/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:44:21 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 16:47:53 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*do_flags(char *return_conv, t_flags *flags, int *length, char **str)
{
	if (flags->precision_exist != 0 && flags->null_char == 0)
	{
		return_conv = ft_update(return_conv, \
			adding_precision_string(flags, return_conv));
		return_conv = ft_update(return_conv, \
			adding_precision_number(flags, return_conv));
	}
	if (flags->minus == 1)
		return_conv = ft_update(return_conv, adding_minus(flags, return_conv));
	else if (flags->plus == 1)
		return_conv = ft_update(return_conv, adding_plus(flags, return_conv));
	else if (flags->space == 1)
		return_conv = ft_update(return_conv, adding_space(flags, return_conv));
	if (flags->width != 0 && flags->null_char == 0)
		return_conv = adding_width(flags, return_conv);
	if (flags->null_char == 1)
		return_conv = adding_width_null_char(flags, return_conv, length, str);
	return (return_conv);
}

char	*continue_conversion(t_flags *flags, va_list *arg, char *return_conv)
{
	if (flags->conversion == 'x' || flags->conversion == 'X')
		return_conv = ft_update(return_conv, conversion_x_cap_x(arg, flags));
	if (flags->conversion == 'b')
		return_conv = ft_update(return_conv, conversion_b(arg, flags));
	if (flags->conversion == '%')
		return_conv = ft_update(return_conv, ft_bchar(1, '%'));
	if (flags->conversion == 'f')
	{
		return_conv = ft_update(return_conv, conversion_f(arg, flags));
		if (flags->plus == 1 && return_conv != 0)
			return_conv = ft_update(return_conv, ft_strjoin("+", return_conv));
		if (flags->zero_padding == 1 && return_conv != 0)
		{
			if (flags->zero_padding == 1)
			{
				return_conv = ft_update(return_conv, ft_strjoin(filler('0', \
					flags->width - ft_strlen(return_conv)), return_conv));
			}
		}
	}
	return (return_conv);
}

char	*start_conversion(t_flags *flags, va_list *arg, int *length, char **str)
{
	char	*return_conv;

	return_conv = ft_strnew(1);
	if (flags->conversion == 'C')
		return_conv = ft_update(return_conv, \
			conversion_wide_c(arg, length, flags));
	if (flags->conversion == 'S')
		return_conv = ft_update(return_conv, conversion_wide_s(arg));
	if (flags->conversion == 's')
		return_conv = ft_update(return_conv, conversion_s(arg));
	if (flags->conversion == 'c')
		return_conv = ft_update(return_conv, conversion_c(arg, length, flags));
	if (flags->conversion == 'i' || flags->conversion == 'd')
		return_conv = ft_update(return_conv, conversion_d_i(arg, flags));
	if (flags->conversion == 'p')
		return_conv = ft_update(return_conv, conversion_p(arg));
	if (flags->conversion == 'D' || flags->conversion == 'u' || \
		flags->conversion == 'U')
		return_conv = ft_update(return_conv, \
			conversion_u_cap_d_cap_u(arg, flags));
	if (flags->conversion == 'o' || flags->conversion == 'O')
		return_conv = ft_update(return_conv, conversion_o_cap_o(arg, flags));
	return_conv = continue_conversion(flags, arg, return_conv);
	return_conv = do_flags(return_conv, flags, length, str);
	return (return_conv);
}
