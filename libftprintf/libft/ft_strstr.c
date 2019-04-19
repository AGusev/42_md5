/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:46:26 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:32:19 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return (char *)(&haystack[i]);
	while (haystack[i])
	{
		j = i;
		k = 0;
		while (haystack[j] == needle[k])
		{
			if (needle[k + 1] == '\0')
			{
				return (char *)(&haystack[i]);
			}
			j++;
			k++;
		}
		i++;
	}
	return (0);
}
