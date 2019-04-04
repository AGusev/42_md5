/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 01:22:57 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 14:22:40 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_bchar(int n, char c)
{
	int		i;
	char	*str;

	str = (char*)malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		ft_bzero(void *s, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	buffer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		buffer[i] = 0;
		i++;
	}
}

int			ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

intmax_t	ft_abs(intmax_t nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
