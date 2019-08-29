/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:58:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_double_res	*init(void)
{
	t_double_res	*r;

	r = (t_double_res *)malloc(sizeof(t_double_res));
	ft_bzero(r, sizeof(t_double_res));
	return (r);
}

t_double_res		*convert_double(long double ld)
{
	t_double_res	*r;
	int				i;

	r = init();
	r->b = ft_get_double_bits(ld);
	if (!ft_is_nan(r) && !ft_is_pos_inf(r) && !ft_is_neg_inf(r))
	{
		r->e = ft_get_double_exp(r->b);
		r->m = ft_get_double_man(r->b);
		i = 0;
		while (i < r->m->r_len - 1)
		{
			r->m->r[i] = r->m->r[i + 1];
			++i;
		}
	}
	return (r);
}
