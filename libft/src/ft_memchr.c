/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:58:50 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:58:50 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *csrc;

	csrc = (unsigned char*)src;
	while (len > 0 && *csrc != (unsigned char)c)
	{
		len--;
		csrc++;
	}
	if (len == 0)
		return (NULL);
	else
		return (csrc);
}
