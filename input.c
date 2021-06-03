/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:35:08 by agusev            #+#    #+#             */
/*   Updated: 2021/06/03 13:50:22 by aleksandr        ###   ########.fr       */
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
