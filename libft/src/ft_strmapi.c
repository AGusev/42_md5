/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:40:34 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:40:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	if (!s)
		return (NULL);
	p = ft_strnew(ft_strlen(s));
	i = 0;
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}
