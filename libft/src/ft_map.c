/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:49:30 by agusev            #+#    #+#             */
/*   Updated: 2019/04/04 15:49:33 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int lenght, int (*f)(int))
{
	int i;
	int *ptr;

	i = 0;
	ptr = (int*)malloc(sizeof(int) * lenght);
	while (i < lenght)
	{
		ptr[i] = f(tab[i]);
		i++;
	}
	return (ptr);
}
