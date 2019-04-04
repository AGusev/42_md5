/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:42:37 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:53:16 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char		*adding_plus(t_flags *flags, char *str)
{
	char	*tmp;

	if (flags->conversion != 'd' && flags->conversion != 'i' && \
			flags->conversion != 'D')
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = ft_strnew(1);
	if (flags->minus == 0)
		tmp = ft_update(tmp, ft_strjoin("+", str));
	return (tmp);
}
