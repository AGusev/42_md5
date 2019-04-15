/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:30:12 by agusev            #+#    #+#             */
/*   Updated: 2019/04/12 20:18:10 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/errno.h>
# include "libft/header/libft.h"

typedef struct		s_gen
{
	int				length;
	uint32_t		h0;
	uint32_t		h1;
	uint32_t		h2;
	uint32_t		h3;
	uint32_t		h4;
	uint32_t		h5;
	uint32_t		h6;
	uint32_t		h7;
//64
	uint64_t		h00;
	uint64_t		h01;
	uint64_t		h02;
	uint64_t		h03;
	uint64_t		h04;
	uint64_t		h05;
	uint64_t		h06;
	uint64_t		h07;
	uint64_t		temp;
	uint64_t		temp1;
	uint64_t		temp2;
	uint64_t		temp3;
	uint64_t		temp4;
	uint64_t		temp5;
	uint64_t		temp6;
	uint64_t		*msg_64;
	uint64_t		aa;
	uint64_t		bb;
	uint64_t		cc;
	uint64_t		dd;
	uint64_t		ee;
	uint64_t		ff;
	uint64_t		gg;
	uint64_t		hh;
	uint64_t		*ww;
	uint64_t		msg_len_64;
//
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
	uint32_t		*w;
	unsigned char	*msg;
	uint32_t		*msg_32;
	int				i;

	uint32_t		msg_len_32;
	int				offset;
// flags
	uint32_t		f_p;
	uint32_t		f_q;
	uint32_t		f_r;
	uint32_t		f_s;
//
	uint32_t		tmp;
	uint32_t		tmp1;
	uint32_t		tmp2;
	uint32_t		tmp3;
	uint32_t		tmp4;
	uint32_t		tmp5;
	uint32_t		tmp6;
	uint32_t		maj;
	uint32_t		ch;
	char			*stdin;
	int				nb_file;
	int				pars;
	int				fd;
}					t_gen;

// md5
int					md5_main_loop(unsigned char *init_msg, size_t len, t_gen *g);
void				md5_print(char *std, t_gen *g);
// sha-256
int					sha256_main_loop(char *init_msg, size_t len, t_gen *g);
void				apply_flagsha256(t_gen *g);
void				sha256_prepare_print(char *std, t_gen *g);
// sha-224
int					sha224_main_loop(char *init_msg, size_t len, t_gen *g);
void				sha224_prepare_print(char *std, t_gen *g);
// sha-384
// sha-512
int					sha512_main_loop(char *init_msg, size_t len, t_gen *g);
void				sha512_prepare_print(char *std, t_gen *g);
// bitwise operations
uint32_t			revers_uint32(uint32_t n);
uint64_t			revers_uint64(uint64_t n);
uint32_t			lor(uint32_t x, uint32_t n);
uint32_t			ror(uint32_t x, uint32_t n);
uint64_t			ror_64(uint64_t x, uint64_t n);
// general
int					apply_flags(t_gen *g, int ac, char **av);
char				*add_zero(char *str);
void				get_new_line(char **ptr);
void				get_line(char **ptr, int fd);
int					no_such_file(t_gen *g, char **av);
void				rotation_print(t_gen *g, char **av);
void				no_rotation_print(t_gen *g, char **av);
void				flag_parsing(t_gen *g, int ac, char **av);
void				set_flags(t_gen *g, int flag, char *read);
void				error(char *read);
void				extra(t_gen *g, char **av);

#endif
