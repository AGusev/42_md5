/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:26 by agusev            #+#    #+#             */
/*   Updated: 2019/04/19 01:35:16 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

t_flags	*flags_struct(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	flags->d = 0;
	flags->e = 0;
	flags->i = 0;
	flags->o = 0;
	flags->ff = 0;
	flags->algo_name = NULL;
	flags->alg_index = -1;
	flags->file = 0;
	flags->stdin = 0;
	flags->hash = 0;
	flags->cipher = 0;
	return (flags);
}

void	flags_struct_del(t_flags *flags)
{
	ft_strdel(&flags->algo_name);
	free(flags);
}
