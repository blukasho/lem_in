/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:54:39 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_errors(void)
{
	if (g_data.width > 2147483646)
		return (-1);
	if (g_data.precision > 2147483641)
		return (-1);
	return (0);
}

int		ft_is_nan(t_double_res *d)
{
	return ((d->b->e == MAX_EXP && d->b->m[62] == '1') ? 1 : 0);
}

int		ft_is_pos_inf(t_double_res *d)
{
	return ((d->b->e == MAX_EXP && !(d->b->s) && d->b->m[62] == '0') ? 1 : 0);
}

int		ft_is_neg_inf(t_double_res *d)
{
	return ((d->b->e == MAX_EXP && (d->b->s) && d->b->m[62] == '0') ? 1 : 0);
}
