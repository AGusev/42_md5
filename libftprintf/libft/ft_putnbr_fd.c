/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:27:15 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:33:23 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long bla;

	bla = n;
	if (bla < 0)
	{
		ft_putchar_fd('-', fd);
		bla = -bla;
	}
	if (bla > 9)
	{
		ft_putnbr_fd((bla / 10), fd);
		ft_putnbr_fd((bla % 10), fd);
	}
	else
		ft_putchar_fd((bla + '0'), fd);
}
