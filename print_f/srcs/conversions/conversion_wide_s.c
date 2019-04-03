/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_wide_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:44:02 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:45:40 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char			*conversion_wide_s(va_list *arg)
{
	wchar_t		*tmp_str;
	char		*str;

	tmp_str = va_arg(*arg, wchar_t *);
	str = ft_wstrdup(tmp_str);
	return (str);
}
