/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:05:46 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 14:40:31 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char				*filler(int c, int len)
{
	char	*s;
	int		i;

	s = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return (s);
}

static void			helper_float(int *sign, long double *n, t_flags *f)
{
	long double		pi;
	int				i;

	i = 0;
	pi = 0.5;
	*sign = 0;
	if (*n < 0)
	{
		*n = -(*n);
		*sign = 1;
	}
	f->precision = (f->precision_exist == 1) ? f->precision : 6;
	while (f->precision >= 0 && i++ < f->precision)
		pi /= 10;
	*n += pi;
}

static char			*ft_ftoa(long double n, t_flags *f)
{
	int			len;
	char		*dst;
	char		*dec;
	int			sign;
	int			pos;

	helper_float(&sign, &n, f);
	dec = ft_itoa_base((long long int)n, 10);
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((f->precision > 0) ? f->precision : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (f->precision > 0)
		dst[pos++] = '.';
	while (pos < len + sign + ((f->precision > 0) ? (f->precision + 1) : 0))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	ft_strdel(&dec);
	return (dst);
}

char				*convert_float_nbr(void *p, t_flags *f)
{
	char		*str;

	str = NULL;
	str = ft_ftoa(*(long double*)p, f);
	return (str);
}

char				*conversion_f(va_list *args, t_flags *f)
{
	long double	n;

	if (!ft_strcmp(f->format, "l"))
		n = (double)va_arg(*args, double);
	else if (!ft_strcmp(f->format, "ll"))
		n = (long double)va_arg(*args, long double);
	else
		n = (double)va_arg(*args, double);
	return (convert_float_nbr((void*)&n, f));
}
