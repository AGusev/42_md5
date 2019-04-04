/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:28:01 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 16:46:16 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

size_t				ft_strlen(const char *str);
intmax_t			ft_abs(intmax_t nb);
void				ft_putchar(char c);
char				*ft_update(char *str, char *update);
void				ft_strdel(char **as);
char				*ft_bchar(int n, char c);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_wstrlen(wchar_t *str);
char				*ft_strdup(const char *s1);
char				*ft_wstrdup(wchar_t *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);
char				*ft_strtoupper(char *str);
char				*ft_strnew(size_t size);
char				*ft_strccrt(const char *str, char c);
char				*ft_strsub(char const *s, unsigned intstart, size_t len);
char				*ft_strjoin(char const *s1, char const*s2);
char				*ft_itoa_base(intmax_t value, int base);
char				*ft_itoa_base_unsigned(uintmax_t value, int base);
char				*ft_itoa_intmax(long long value);
char				*ft_itoa_unsigned(uintmax_t value);
char				*ft_itoa_unsigned(uintmax_t value);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
