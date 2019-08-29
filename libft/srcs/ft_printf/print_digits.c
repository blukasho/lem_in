/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:45:00 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_put_long_nbr(__int128 d)
{
	if (d > 9 && !(ft_put_long_nbr(d / 10)))
		ft_printf_put_char((d % 10) + 48);
	else
		ft_printf_put_char((d % 10) + 48);
	return (0);
}

static void		print_spaces(int l, __int128 d)
{
	if ((g_data.precision == 0 && d == 0))
		++g_data.width;
	if (ft_strchr(g_data.flags, '0') && !ft_strchr(g_data.flags, '-')
		&& g_data.precision == -1 && g_data.width != 0)
		g_data.precision = g_data.width;
	else if (g_data.precision < l)
	{
		while (g_data.width-- > l)
			ft_printf_put_char(' ');
	}
	else
		while (g_data.width-- > g_data.precision)
			ft_printf_put_char(' ');
}

static void		print_space_flag(void)
{
	if (ft_strchr(g_data.flags, ' ') && !ft_strchr(g_data.flags, '+')
		&& --g_data.width && srcrpl(g_data.flags, ' ', -1))
		ft_printf_put_char(' ');
}

void			print_all_digits(__int128 d)
{
	int			l;

	l = ft_len_nbr(d);
	if (d < 0 || ft_strchr(g_data.flags, '+'))
		--g_data.width;
	if (ft_strchr(g_data.flags, ' ') && d > -1)
		print_space_flag();
	if (!ft_strchr(g_data.flags, '-'))
		print_spaces(ft_len_nbr(d), d);
	if (d < 0 && (d = -d))
		ft_printf_put_char('-');
	else if (ft_strchr(g_data.flags, '+'))
		ft_printf_put_char('+');
	if (g_data.precision > l)
		while (g_data.precision > l++)
			ft_printf_put_char('0');
	if (!(g_data.precision == 0 && d == 0))
		ft_put_long_nbr(d);
	if (ft_strchr(g_data.flags, '-'))
		print_spaces(ft_len_nbr(d), d);
}

void			print_digits(va_list ap)
{
	if ((g_data.specifier == 'd' || g_data.specifier == 'i')
			&& !g_data.length)
		print_all_digits(va_arg(ap, int));
	else if ((g_data.specifier == 'd' || g_data.specifier == 'i')
			&& g_data.length == 1)
		print_all_digits(va_arg(ap, long));
	else if ((g_data.specifier == 'd' || g_data.specifier == 'i')
			&& g_data.length == 2)
		print_all_digits(va_arg(ap, long long));
	else if ((g_data.specifier == 'd' || g_data.specifier == 'i')
			&& g_data.length == 4)
		print_all_digits((short)va_arg(ap, int));
	else if ((g_data.specifier == 'd' || g_data.specifier == 'i')
			&& g_data.length == 5)
		print_all_digits((char)va_arg(ap, int));
}
