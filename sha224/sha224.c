/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:24:40 by agusev            #+#    #+#             */
/*   Updated: 2019/04/21 01:36:53 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"
#include "../sha224/sha224.h"
#include "sha224.h"

extern t_strings	g_ss[100];
extern int			g_ss_cnt;

static char	*sha224_digest(u_char digest[32])
{
	u_int	i;
	char	*result;
	char	*s;

	result = ft_strnew(0);
	i = 0;
	while (i < 24)
	{
		s = ft_ssprintf("%02x", digest[i]);
		ft_strsetdel(&result, ft_strjoin(result, s));
		ft_strdel(&s);
		i++;
	}
	return (result);
}

char		*sha224_file(int fd)
{
	u_char	digest[32];
	u_char	buf[1024];
	t_ctx	ctx;
	int		len;

	sha224_init(&ctx);
	while ((len = read(fd, buf, 1024)) > 0)
		sha256_update(&ctx, buf, len);
	sha256_final(&ctx, digest);
	return (sha224_digest(digest));
}

static void	process_files(size_t f, u_int cnt, char **av)
{
	u_int		i;
	int			fd;
	char		*sha224;
	extern int	errno;

	i = 0;
	while (i < cnt)
	{
		fd = open(av[i], O_RDONLY);
		if (fd != -1)
		{
			print_hash((f & 8) && !(f & 4) ? SHA224_R : SHA224_TPL,
				av[i], (sha224 = sha224_file(fd)), f);
			ft_strdel(&sha224);
			close(fd);
		}
		else
			file_error("sha224", av[i], errno);
		i++;
	}
}

char		*sha224_str(char *s)
{
	u_char	digest[32];
	t_ctx	ctx;

	sha224_init(&ctx);
	sha256_update(&ctx, (u_char *)s, ft_strlen(s));
	sha256_final(&ctx, digest);
	return (sha224_digest(digest));
}

void		process_sha224(size_t f, int cnt, char **av)
{
	char	*s;
	char	*sha224;
	int		i;

	s = NULL;
	if ((f & 1024) || (cnt == 0 && g_ss_cnt == 0))
		s = read_stdin();
	if (s && ft_strlen(s) != 0)
	{
		sha224 = sha224_str(s);
		print_hash((f & 1024) ? "%s%s\n" : "%s\n", s, sha224,
			(f & 1024) ? 0 : 4);
		ft_strdel(&s);
		ft_strdel(&sha224);
	}
	i = -1;
	while (++i < g_ss_cnt)
	{
		s = ft_ssprintf("\"%s\"", g_ss[i].s);
		print_hash((g_ss[i].f & 8) && !(g_ss[i].f & 4) ? SHA224_R : SHA224_TPL,
			s, (sha224 = sha224_str(g_ss[i].s)), g_ss[i].f);
		ft_strdel(&sha224);
		ft_strdel(&s);
	}
	process_files(f, cnt, av);
}