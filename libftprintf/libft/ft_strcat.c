/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:08:41 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:32:19 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int c;
	int g;

	c = 0;
	g = 0;
	while (dest && dest[c])
	{
		c++;
	}
	while (src && src[g])
	{
		dest[c] = src[g];
		c++;
		g++;
	}
	dest[c] = '\0';
	return (dest);
}
