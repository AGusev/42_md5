/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:11:40 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:33:23 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;

	new = f(lst);
	new = ft_lstnew(new->content, new->content_size);
	if (lst == NULL || f == NULL || new == NULL)
		return (NULL);
	first = new;
	while (lst->next)
	{
		new->next = ft_lstnew(new->content, new->content_size);
		if (new->next == NULL)
		{
			free(new);
			new = NULL;
			return (NULL);
		}
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
