/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:38:40 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:43:28 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharlen(wchar_t wc)
{
	int size;

	size = 0;
	if (wc <= 127)
		size = 1;
	else if (wc <= 2047)
		size = 2;
	else if (wc <= 65535)
		size = 3;
	else if (wc <= 1114111)
		size = 4;
	return (size);
}
