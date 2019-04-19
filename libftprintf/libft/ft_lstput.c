/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:09:47 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:33:23 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstput(t_list **alst, size_t position)
{
	t_list	*lstnew;
	t_list	*new;

	new = *alst;
	lstnew = (t_list*)malloc(sizeof(t_list));
	lstnew->content = NULL;
	if (alst == NULL || (int)position <= 0 || lstnew == NULL)
		return ;
	if (position == 1)
	{
		ft_lstadd(alst, lstnew);
		return ;
	}
	while (new->next && position > 2)
	{
		new = new->next;
		position--;
	}
	lstnew->next = new->next;
	new->next = lstnew;
}
