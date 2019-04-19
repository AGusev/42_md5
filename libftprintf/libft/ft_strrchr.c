/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 10:45:51 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:32:19 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			k = i;
			count++;
		}
		i++;
	}
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	if (count > 0)
		return ((char*)s + k);
	else
		k = 0;
	return (NULL);
}
