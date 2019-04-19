/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_doubleint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:52:10 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:31:22 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_doubleint(int **arr, int len)
{
	if (!arr || !*arr)
		return ;
	while (len)
		ft_intdel(&arr[--len]);
	free(arr);
}
