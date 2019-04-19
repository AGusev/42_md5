/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:56:15 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:33:23 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, size_t size)
{
	char	*newptr;

	if (!(newptr = ft_strnew(size)))
		return (NULL);
	if (ptr)
	{
		ft_strcpy(newptr, ptr);
		ft_strdel(&ptr);
	}
	return (newptr);
}
