/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 09:53:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_3(char *s, int l, char c)
{
	while (g_data.width > l && g_data.width-- > g_data.precision)
		ft_printf_put_char(c);
	print_precision_octal(l);
	ft_printf_put_str(s);
}

static void		print_2(char *s, int l)
{
	char		c;

	if (g_data.precision > -1 || g_data.flags[1] != '0')
		c = ' ';
	else
		c = '0';
	if (g_data.flags[0] == '#')
	{
		if (g_data.precision > l + 1)
		{
			g_data.width -= g_data.precision;
			print_width_octal(c);
		}
		else
			while (g_data.width-- > l + 1)
				ft_printf_put_char(c);
		print_hesh();
		while (g_data.precision-- > l + 1)
			ft_printf_put_char('0');
		ft_printf_put_str(s);
	}
	else
		print_3(s, l, c);
}

static void		print(char *s, int l)
{
	if (g_data.flags[4] == '-')
	{
		if (g_data.flags[0] == '#')
		{
			if (g_data.precision > l + 1)
			{
				g_data.width -= g_data.precision;
				while (g_data.precision-- > l)
					ft_printf_put_char('0');
			}
			else
			{
				print_hesh();
				g_data.width -= l + 1;
			}
		}
		else
			print_precision_octal(l);
		ft_printf_put_str(s);
		print_width_octal(' ');
	}
	else
		print_2(s, l);
}

static void		preparate(__int128 d, char *res)
{
	char		tmp;
	int			i;

	i = 0;
	if (!d && g_data.precision == -1 && (g_data.flags[0] = -1))
		res[i++] = '0';
	while (d > 0)
	{
		res[i++] = (d % 8) + 48;
		d /= 8;
	}
	res[i] = '\0';
	d = 0;
	while (i > d)
	{
		tmp = res[d];
		res[d++] = res[--i];
		res[i] = tmp;
	}
	i = ft_strlen(res);
	print(res, i);
}

void			print_octal(va_list ap)
{
	char		res[40];

	if (g_data.specifier == 'o' && !g_data.length)
		preparate(va_arg(ap, unsigned int), res);
	else if (g_data.specifier == 'o' && g_data.length == 1
			&& srcrpl(g_data.flags, '+', -1))
		preparate(va_arg(ap, unsigned long), res);
	else if (g_data.specifier == 'o' && g_data.length == 2
			&& srcrpl(g_data.flags, '+', -1))
		preparate(va_arg(ap, unsigned long long), res);
	else if (g_data.specifier == 'o' && g_data.length == 4
			&& srcrpl(g_data.flags, '+', -1))
		preparate((unsigned short)va_arg(ap, unsigned int), res);
	else if (g_data.specifier == 'o' && g_data.length == 5
			&& srcrpl(g_data.flags, '+', -1))
		preparate((unsigned char)va_arg(ap, unsigned int), res);
}
