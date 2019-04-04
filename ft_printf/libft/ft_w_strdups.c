/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_strdups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 01:29:39 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 14:14:38 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2)
		ft_strcpy(s2, s1);
	return (s2);
}

char	*ft_wstrdup(wchar_t *s1)
{
	int		i;
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_wstrlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = (char)s1[i];
		++i;
	}
	s2[i] = '\0';
	return (s2);
}
