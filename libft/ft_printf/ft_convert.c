/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:47:43 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:46:52 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	convert_u(t_param *arg, va_list *ap)
{
	unsigned long long n;

	n = 0;
	if (!(ft_strcmp(arg->length, "")))
		n = va_arg(*ap, unsigned int);
	else if (!(ft_strcmp(arg->length, "hh")))
		n = (unsigned char)va_arg(*ap, unsigned int);
	else if (!(ft_strcmp(arg->length, "h")))
		n = (unsigned short)va_arg(*ap, unsigned int);
	else if (!(ft_strcmp(arg->length, "ll")))
		n = va_arg(*ap, unsigned long long int);
	else if (!(ft_strcmp(arg->length, "l")))
		n = va_arg(*ap, unsigned long int);
	else if (!(ft_strcmp(arg->length, "j")))
		n = va_arg(*ap, uintmax_t);
	else if (!(ft_strcmp(arg->length, "z")))
		n = va_arg(*ap, size_t);
	return (n);
}

long long			convert(t_param *arg, va_list *ap)
{
	long long	n;

	n = 0;
	if (!(ft_strcmp(arg->length, "")))
		n = va_arg(*ap, int);
	else if (!(ft_strcmp(arg->length, "hh")))
		n = (char)va_arg(*ap, int);
	else if (!(ft_strcmp(arg->length, "h")))
		n = (short int)va_arg(*ap, int);
	else if (!(ft_strcmp(arg->length, "ll")))
		n = va_arg(*ap, long long);
	else if (!(ft_strcmp(arg->length, "l")))
		n = va_arg(*ap, long);
	else if (!(ft_strcmp(arg->length, "j")))
		n = va_arg(*ap, intmax_t);
	else if (!(ft_strcmp(arg->length, "z")))
		n = va_arg(*ap, size_t);
	return (n);
}
