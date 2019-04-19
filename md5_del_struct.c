/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdStruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:46 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 00:15:19 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_md	*md5_struct(void)
{
	t_md	*lst;
	lst = (t_md*)malloc(sizeof(t_md));
	lst->a = 0;
	lst->aa = 0;
	lst->next = NULL;
	return (lst);
}

void	md5_del_struct(t_md *md)
{
	int		i;
	t_md	*tmp;

	i = 0;
	while (i < 4)
	{
		tmp = md->next;
		free(md);
		md = tmp;
		i++;
	}
}
