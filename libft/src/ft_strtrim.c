/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:39:09 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:39:10 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const *snew;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	snew = s + ft_strlen(s) - 1;
	while (*snew == ' ' || *snew == '\t' || *snew == '\n')
		snew--;
	return (ft_strsub(s, 0, snew - s + 1));
}
