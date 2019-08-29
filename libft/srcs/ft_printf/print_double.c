/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:30:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_3(int m)
{
	while (g_data.width-- > g_data.precision)
		ft_printf_put_char(' ');
	if (g_data.flags[3] == '+' || m)
	{
		if (m)
			ft_printf_put_char('-');
		else
			ft_printf_put_char('+');
	}
}

static void			print_2(t_double_res *d)
{
	if (!print_inf(d) && !print_nan(d))
	{
		if (g_data.width > 0)
			g_data.width -= ft_get_real_len(d->e->r, d->e->r_len) + 1;
		if (g_data.precision > 0)
			--g_data.width;
		if (g_data.flags[1] == '0')
		{
			if (g_data.flags[3] == '+' || d->b->s)
			{
				if (d->b->s)
					ft_printf_put_char('-');
				else
					ft_printf_put_char('+');
			}
			while (g_data.width-- > g_data.precision)
				ft_printf_put_char('0');
		}
		else
			print_3(d->b->s);
		print_t_double(d);
		if (g_data.flags[0] == '#' && g_data.precision == 0)
			ft_printf_put_char('.');
	}
}

static void			print_1(t_double_res *d)
{
	int				i;

	if (!print_inf(d) && !print_nan(d))
	{
		if (g_data.flags[3] == '+' || d->b->s)
		{
			if (d->b->s)
				ft_printf_put_char('-');
			else
				ft_printf_put_char('+');
		}
		i = g_print_symbols;
		print_t_double(d);
		g_data.width = g_data.width - (g_print_symbols - i);
		if (g_data.flags[0] == '#' && g_data.precision == 0)
			ft_printf_put_char('.');
		while (g_data.width-- > 0)
			ft_printf_put_char(' ');
	}
}

static void			print(long double d)
{
	t_double_res	*r;

	r = convert_double(d);
	if (g_data.precision == -1)
		g_data.precision = 6;
	if (!ft_is_nan(r) && !ft_is_pos_inf(r) && !ft_is_neg_inf(r))
		round_double(r);
	if (!ft_is_nan(r))
	{
		if (g_data.flags[0] == '#' && g_data.precision == 0)
			--g_data.width;
		if (g_data.flags[3] == '+' || r->b->s)
			--g_data.width;
		if (g_data.flags[2] == ' ' && g_data.flags[3] != '+' && !r->b->s)
		{
			--g_data.width;
			ft_printf_put_char(' ');
		}
	}
	if (g_data.flags[4] == '-')
		print_1(r);
	else
		print_2(r);
	clear_t_double_res(r);
}

void				print_double(va_list ap)
{
	if (g_data.length == 3)
		print((long double)va_arg(ap, long double));
	else
		print(va_arg(ap, double));
}
