/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 00:41:45 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 12:45:52 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char		*conversion_s(va_list *arg)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(*arg, char *);
	if (tmp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(tmp);
	return (str);
}
