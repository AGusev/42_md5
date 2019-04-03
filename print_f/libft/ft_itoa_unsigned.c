/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 01:27:39 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 01:27:40 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*itoa_filler(char *tab, uintmax_t value)
{
	uintmax_t	tmp;
	int			size;
	char		*str;

	size = 0;
	tmp = value;
	while (tmp /= 10)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % 10];
		size--;
		value = value / 10;
	}
	return (str);
}

char			*ft_itoa_unsigned(uintmax_t value)
{
	char		*str;
	char		*tab;

	tab = "0123456789abcdef";
	str = itoa_filler(tab, value);
	return (str);
}
