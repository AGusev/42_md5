/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 04:33:19 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 04:33:37 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	char	*res;

	res = str;
	while (*str != '\0')
	{
		if (*str <= 'z' && *str >= 'a')
			*str = *str - 32;
		str++;
	}
	return (res);
}