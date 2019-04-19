/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:31:22 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:33:23 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*newdest;
	unsigned char	*newsrc;

	newdest = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (newsrc < newdest)
	{
		while (len--)
			newdest[len] = newsrc[len];
	}
	else
		ft_memcpy(newdest, newsrc, len);
	return (dst);
}
