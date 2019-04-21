/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:35:08 by agusev            #+#    #+#             */
/*   Updated: 2019/04/21 00:39:05 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*read_stdin(void)
{
	char	*line;
	char	*buf;

	buf = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_strsetdel(&buf, ft_strjoin(buf, line));
		ft_strdel(&line);
		ft_strsetdel(&buf, ft_strjoin(buf, "\n"));
	}
	return (buf);
}
