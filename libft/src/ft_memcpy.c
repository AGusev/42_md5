/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:44:35 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:44:36 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdst;

	csrc = (char *)src;
	cdst = dst;
	while (0 < n)
	{
		*cdst++ = *csrc++;
		n--;
	}
	return (dst);
}
