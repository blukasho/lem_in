/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_double.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:33:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		clear_t_double_res(t_double_res *r)
{
	if (r->b)
		ft_memdel((void **)&r->b);
	if (r->e)
	{
		ft_memdel((void **)&r->e->r);
		ft_memdel((void **)&r->e);
	}
	if (r->m)
	{
		if (r->m->r)
			ft_memdel((void **)&r->m->r);
		if (r->m->div)
			ft_memdel((void **)&r->m->div);
		if (r->m->per)
			ft_memdel((void **)&r->m->per);
		ft_memdel((void **)&r->m);
	}
	if (r)
		ft_memdel((void **)&r);
}

int			srch_int_in_arr(int *a, int a_len, int srch)
{
	while (--a_len >= 0)
		if (a[a_len] != srch)
			return (1);
	return (0);
}

void		move_int_arr(int *a, int a_len)
{
	while (a[--a_len] == 0)
		;
	while (a_len >= 0)
	{
		a[a_len + 1] = a[a_len];
		a[a_len] = 0;
		--a_len;
	}
}

void		print_t_double(t_double_res *r)
{
	int		i;
	int		m;

	i = r->e->r_len;
	while (i && (r->e->r[--i]) == 0)
		;
	while (i >= 0)
		ft_printf_put_char(r->e->r[i--] + 48);
	if (g_data.precision > 0)
	{
		m = 0;
		i = g_data.precision;
		ft_printf_put_char('.');
		while (i-- && m < r->m->r_len)
			ft_printf_put_char(r->m->r[m++] + 48);
		while (i-- >= 0)
			ft_printf_put_char('0');
	}
}
