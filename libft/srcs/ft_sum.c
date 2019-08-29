/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/27 15:10:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_neg_exp_of_digit		*init(t_neg_exp_of_digit *a, t_neg_exp_of_digit *b)
{
	t_neg_exp_of_digit	*res;
	int					i;

	i = -1;
	res = (t_neg_exp_of_digit *)malloc(sizeof(t_neg_exp_of_digit));
	ft_bzero(res, sizeof(t_neg_exp_of_digit));
	res->r_len = a->r_len + b->r_len;
	res->r = (int *)malloc(res->r_len * sizeof(int));
	ft_bzero(res->r, res->r_len * sizeof(int));
	while (++i < a->r_len)
		res->r[i] = a->r[i];
	return (res);
}

t_neg_exp_of_digit		*ft_sum(t_neg_exp_of_digit *a, t_neg_exp_of_digit *b)
{
	t_neg_exp_of_digit	*sum;
	int					i;

	i = -1;
	sum = init(a, b);
	while (++i < b->r_len)
		sum->r[i] += b->r[i];
	i = sum->r_len;
	while (--i >= 0)
		if (sum->r[i] > 9)
		{
			sum->r[i - 1] += sum->r[i] / 10;
			sum->r[i] = sum->r[i] % 10;
		}
	return (sum);
}
