/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:51:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	round_exp(t_double_res *d)
{
	int		i;
	int		l;

	i = 0;
	l = d->e->r_len;
	if (d->m->r[0] > 9)
	{
		d->m->r[0] = d->m->r[0] % 10;
		++(d->e->r[0]);
	}
	while (l && d->e->r[--l] == 0)
		;
	while (i <= l)
	{
		if (d->e->r[i] > 9 && ++(d->e->r[i + 1]))
			d->e->r[i] = d->e->r[i] % 10;
		++i;
	}
}

static void	round_presicion_zero(t_double_res *d)
{
	if ((d->e->r[0]) % 2 && (d->m->r[0]) >= 5 && d->m->r[1] == 0)
		++(d->e->r[0]);
	else if (!(d->e->r[0] % 2) && (d->m->r[0] > 5) && d->m->r[1] == 0)
		++(d->e->r[0]);
	else if (!(d->e->r[0] % 2) && (d->m->r[0] >= 5) && d->m->r[1] != 0)
		++(d->e->r[0]);
	else if ((d->e->r[0] % 2) && (d->m->r[0] >= 5) && d->m->r[1] != 0)
		++(d->e->r[0]);
	else if (!(d->e->r[0] % 2) && (d->m->r[0] >= 5) && d->m->r[2] != 0)
		++(d->e->r[0]);
}

static int	check(t_double_res *d, int i)
{
	return ((d->m->r[i] == 0 && d->m->r[i + 1] == 0) ? 1 : 0);
}

void		round_double(t_double_res *d)
{
	int		i;

	i = g_data.precision;
	if (i > 0)
	{
		if (i < d->m->r_len - 1 && !check(d, i))
		{
			(d->m->r[i]) += 5;
			while (i > 0)
			{
				if (d->m->r[i] > 9)
				{
					++(d->m->r[i - 1]);
					d->m->r[i] = d->m->r[i] % 10;
				}
				--i;
			}
			round_exp(d);
		}
	}
	else if (i == 0)
	{
		round_presicion_zero(d);
		round_exp(d);
	}
}
