/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:57:29 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:33:23 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *bla;

	bla = (t_list*)malloc(sizeof(t_list));
	if (bla == NULL)
		return (NULL);
	if (content == NULL)
	{
		bla->content = NULL;
		bla->content_size = 0;
		bla->next = NULL;
	}
	else
	{
		bla->content = (void*)malloc(sizeof(void) * content_size);
		if (bla->content == NULL)
		{
			free(bla);
			bla = NULL;
			return (NULL);
		}
		ft_memcpy(bla->content, content, content_size);
		bla->content_size = content_size;
		bla->next = NULL;
	}
	return (bla);
}
