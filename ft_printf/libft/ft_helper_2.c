/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:18:07 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 14:23:18 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (char *)s;
}

char	*ft_strccrt(const char *str, char c)
{
	size_t		i;
	size_t		j;
	char		*new;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		++i;
	if (ft_strlen(str) == i - 1)
		return (NULL);
	new = (char *)malloc(sizeof(char) * i + 1);
	j = 0;
	while (j < i)
	{
		new[j] = str[j];
		++j;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_update(char *str, char *update)
{
	free(str);
	str = update;
	return (str);
}
