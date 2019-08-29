/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_double_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:44:53 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/29 13:26:46 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_sum_two_digits	*init(void)
{
	t_sum_two_digits	*res;

	res = (t_sum_two_digits *)malloc(sizeof(t_sum_two_digits));
	ft_bzero(res, sizeof(t_sum_two_digits));
	res->r_len = 1;
	res->r = (int *)malloc(res->r_len * sizeof(int));
	ft_bzero(res->r, res->r_len * sizeof(int));
	return (res);
}

t_sum_two_digits		*ft_get_double_exp(t_bits *b)
{
	t_sum_two_digits	*res;
	t_sum_two_digits	*tmp;
	t_pos_exp_of_digit	*p_ex;
	int					exp;
	int					bits;

	bits = 63;
	exp = b->e - 16383;
	res = init();
	while (exp >= 0 && bits >= 0)
	{
		if (b->m[bits] == '1')
		{
			tmp = res;
			p_ex = ft_pos_exp_of_digit(2, exp);
			res = ft_sum_two_digits(res->r, p_ex->r, res->r_len, p_ex->r_len);
			ft_memdel((void **)&tmp->r);
			ft_memdel((void **)&tmp);
			ft_memdel((void **)&p_ex->r);
			ft_memdel((void **)&p_ex);
		}
		--bits;
		--exp;
	}
	return (res);
}
