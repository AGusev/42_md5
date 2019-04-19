/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:34:20 by agusev            #+#    #+#             */
/*   Updated: 2019/04/18 23:47:53 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"
#include <stdio.h>

void	free_flags(t_flags * flags)
{
	flags->p = 0;
	flags->s = 0;
}

void	hash_print(char *input, t_flags *flags, const t_alg *alg)
{
	if (flags->p)
		ft_printf("%s", input);
	else if (!flags->q && flags->s && !flags->file && !flags->r)
	{
		ft_print_upper(flags->algo_name);
		ft_printf(" (\"%s\") = ", input);
	}
	alg[flags->alg_index](input, ft_strlen(input));
 	if (!flags->q && flags->r && !flags->file && !flags->p)
		ft_printf(" \"%s\"\n", input);
/* 	else if (!flags->q && flags->file)
	{
		ft_printf(" %s", input);
	} */
	else
		ft_printf("\n");
	free_flags(flags);
}

void	cipher_init(char *input, t_flags *flags, const t_alg *alg)
{
	if (flags->d)
		flags->alg_index++;
	alg[flags->alg_index](input, ft_strlen(input));
}

void	search_for_func(char *input, t_flags *flags)
{
	const t_alg alg[ALGORITHM_NUM] = {MD5, sha256, sha224, sha384, sha512, base_64, dec_base_64};

	if (flags->hash)
		hash_print(input, flags, alg);
	else if (flags->cipher)
		cipher_init(input, flags, alg);
}
