/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:35:18 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 21:39:17 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
#define SSL_H

#include "./libftprintf/libft.h"

typedef unsigned int			t_uint;
typedef unsigned char			t_uchar;
typedef unsigned long long int	t_ullint;

// (encode & decode)
#define	algo_num 6
#define	HASH_NUM 5

# define BUFF_SIZE 99999

# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6
# define H 7
# define E0 0
# define MA 1
# define T2 2
# define E1 3
# define CH 4
# define T1 5

typedef struct	s_flags
{
	// hash
	int		p;
	int		q;
	int		r;
	int		s;
	//other
	char	*algo_name;
	int		alg_index;
	int		file;
	int		stdin;
	int		hash;
}				t_flags;

typedef	struct	s_algorithm
{
	char			*name;
	struct	s_algorithm	*next;
}				t_algorithm;

typedef struct	s_md
{
  unsigned int	a;
  unsigned int	aa;
  struct s_md		*next;
}				t_md;
unsigned int	hash_p;

typedef void	(*t_alg)(char *, size_t);

// create/delete struct
t_algorithm			*algorithm_create(char *command);
void				algorithm_delete(t_algorithm *algorithm);
t_flags				*flags_struct(void);
void				flags_struct_del(t_flags *flags);
t_md				*md5_struct(void);
void				md5_del_struct(t_md *md);

// read args
void				read_input(t_flags *flags, t_algorithm *algorithm, int argc, char **argv);
int					search_for_algorithm(t_algorithm *algorithm, t_flags *flags, char *argv);

// errors
void				error_algorithm(t_algorithm *algorithm, char *arg);
void				error_option(char *arg);
void				error_file(char *arg, t_flags *flags);
void				error_usage();

// read fd
char				*fd_read(int fd);

// searching right algorithm
void				search_for_func(char *input,  t_flags *flags);

// bits operations
t_uint				fBit(t_uint x, t_uint y, t_uint z);
t_uint				gBit(t_uint x, t_uint y, t_uint z);
t_uint				hBit(t_uint x, t_uint y, t_uint z);
t_uint				lBit(t_uint x, t_uint y, t_uint z);
t_uint				ROR_32(t_uint a, int s);
t_ullint			ROR_64(t_ullint x, int n);

// alignment for sha256 & MD5
t_uchar				*align(ssize_t size, char *input);
ssize_t				define_size(ssize_t len);

// bonus from stdin
char				**from_stdin(int *argc, t_flags *flags);
char				**split_into_array(char *arr, char elem);



// MD5
void		md5_reverse(t_md *hash, t_uint *param, t_uint (*f)(t_uint, t_uint, t_uint));
void		md5_transform(int *i, int *x, t_md *hash, t_uint *arr);
void		equal(t_md *hash);
void		h0_plus_a(t_md *hash);
t_uint		*md5_length(t_uchar *bef, ssize_t new_size, ssize_t size);
void		md5_print(t_md *hash);
t_uint		*md5_shift(ssize_t len, t_uint *data, ssize_t i);
void		md5_init(t_md *lst);
void		md5_algorithm(t_md *hash, ssize_t size, t_uint *arr);


// sha512 384
t_uchar				*sha512_align(t_ullint size, char *input);
t_ullint			sha512_define_size(t_ullint len);
t_ullint			*sha512_to_int(t_uchar *bef, ssize_t news, t_ullint s);
t_ullint			*sha512_len(t_ullint len, t_ullint *data, t_ullint i);
t_ullint			*sha512_main_loop(t_ullint s, t_ullint *a, t_ullint *hash);

// sha 256 224

t_uint				*sha256_hash_cpy(t_uint *hash);
t_uint				*sha256_transform(t_uint *w, t_uint *arr);
t_uint				*sha256_hash_sum(t_uint *hash, t_uint *tmp);
t_uint				*sha256_algo(t_uint *fo, t_uint *tmp, int i, t_uint *words);
t_uint				*sha256_algorithm(t_uint *tmp, t_uint *words);
t_uint				*sha256_to_int(t_uchar *bef, ssize_t new_size, ssize_t size);
t_uint				*sha256_main_loop(ssize_t size, t_uint *arr, t_uint *hash);
//
t_uint				*sha224_len(ssize_t len, t_uint *data, ssize_t i);
//
t_ullint			*sha512_hash_cpy(t_ullint *hash);
t_ullint			*sha512_transform(t_ullint *w, t_ullint *arr);
t_ullint			*sha512_hash_sum(t_ullint *hash, t_ullint *tmp);
t_ullint			sha512_const2(int i);
t_ullint			sha512_const(int i);
t_ullint			*sha512_algo(t_ullint *fo, t_ullint *tmp, int i, t_ullint *words);
t_ullint			*sha512_algorithm(t_ullint *tmp, t_ullint *words);
t_ullint			*sha512_main_loop(t_ullint s, t_ullint *a, t_ullint *hash);
t_ullint			sha512_define_size(t_ullint len);
t_uchar				*sha512_align(t_ullint size, char *input);
t_ullint			*sha512_to_int(t_uchar *bef, ssize_t news, t_ullint s);
t_ullint			*sha512_len(t_ullint len, t_ullint *data, t_ullint i);
t_ullint			*sha512_init(t_ullint *hash);
void				sha512_print(t_ullint *hash);

// hash algorithm
void				MD5(char *input, size_t len);
void				sha256(char *input, size_t len);
void				sha512(char *input, size_t len);
void				sha384(char *input, size_t len);
void				sha224(char *input, size_t len);

#endif
