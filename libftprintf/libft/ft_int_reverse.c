/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:53:15 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:31:22 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_int_reverse(int *arr, int len)
{
	int i;

	i = 0;
	len--;
	while (i < len)
	{
		ft_swap(&arr[i], &arr[len]);
		i++;
		len--;
	}
	return (arr);
}
