/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 01:29:26 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 01:29:28 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	source_len;
	char	*result;

	source_len = ft_strlen(src) + 1;
	result = (char *)ft_memcpy(dst, src, source_len);
	return (result);
}
