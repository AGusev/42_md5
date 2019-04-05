/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:56:19 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:56:20 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	char	*temp_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	if (!(str = (char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	temp_str = str;
	while (*s1 != '\0')
		*temp_str++ = *s1++;
	while (*s2 != '\0')
		*temp_str++ = *s2++;
	*temp_str++ = '\0';
	return (str);
}
