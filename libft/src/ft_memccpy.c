/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:58:44 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:58:45 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char *csrc;
	unsigned char		*cdst;
	size_t				i;

	i = 0;
	csrc = (const unsigned char*)src;
	cdst = (unsigned char*)dst;
	while (n > i)
	{
		cdst[i] = csrc[i];
		if (cdst[i] == (unsigned char)c)
			return ((void *)cdst + i + 1);
		i++;
	}
	return (NULL);
}
