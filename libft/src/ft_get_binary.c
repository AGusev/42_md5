/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:36:11 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:36:12 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_binary(unsigned char octet)
{
	unsigned char	i;
	char			*res;
	int				counter;

	res = ft_strnew(8);
	counter = 0;
	i = 128;
	while (i)
	{
		if (i & octet)
			res[counter++] = '1';
		else
			res[counter++] = '0';
		i >>= 1;
	}
	return (res);
}
