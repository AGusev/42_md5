/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:41:54 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:45:55 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char			*conversion_p(va_list *arg)
{
	char		*answer;
	intmax_t	tmp;

	answer = ft_strnew(1);
	tmp = va_arg(*arg, unsigned long);
	answer = ft_update(answer, ft_itoa_base(tmp, 16));
	answer = ft_update(answer, ft_strjoin("0x", answer));
	return (answer);
}
