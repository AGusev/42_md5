/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:18:23 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:33:23 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long bla;

	bla = n;
	if (bla < 0)
	{
		ft_putchar('-');
		bla = -bla;
	}
	if (bla > 9)
	{
		ft_putnbr(bla / 10);
		ft_putnbr(bla % 10);
	}
	else
		ft_putchar(bla + '0');
}
