/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:54:13 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:31:22 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intcpy(int *new, int *old, int size)
{
	int i;

	i = 0;
	new = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}
