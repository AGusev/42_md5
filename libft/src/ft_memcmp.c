/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:58:55 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:58:57 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (len > 0 && *cs1 == *cs2)
	{
		cs1++;
		cs2++;
		len--;
	}
	if (len == 0)
		return (0);
	else
		return (*cs1 - *cs2);
}
