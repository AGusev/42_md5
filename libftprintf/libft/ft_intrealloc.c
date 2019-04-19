/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:54:18 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 00:10:34 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_int_realloc(int *arr, int size, int new_size)
{
	int *new;
	int i;

	i = 0;
	new = (int*)malloc(sizeof(int) * new_size);
	while (i < size)
	{
		new[i] = arr[i];
		i++;
	}
	free(arr);
	return (new);
}
