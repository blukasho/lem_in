/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexdecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:04:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_hexdecimal(va_list ap)
{
	if (!g_data.length)
		print_hex(va_arg(ap, unsigned int));
	else if (g_data.length == 1)
		print_hex(va_arg(ap, unsigned long));
	else if (g_data.length == 2)
		print_hex(va_arg(ap, unsigned long long));
	else if (g_data.length == 4)
		print_hex((unsigned short)va_arg(ap, unsigned int));
	else if (g_data.length == 5)
		print_hex((unsigned char)va_arg(ap, unsigned int));
}

static void		strrev(char s[])
{
	int			end;
	int			start;
	char		c;

	start = 0;
	end = ft_strlen(s);
	while (--end > start)
	{
		c = s[start];
		s[start++] = s[end];
		s[end] = c;
	}
}

static void		print2(int l, char *res, __int128 h)
{
	if (g_data.flags[0] == '#' && l > 1 && res[0] != '0')
		g_data.width -= 2;
	if (g_data.specifier == 'p' && g_data.flags[0] == '#' && !h)
		g_data.width -= 2;
	if (g_data.flags[1] == '0' && g_data.precision == -1)
	{
		if (g_data.specifier == 'p' || (g_data.flags[0] == '#' && h > 0))
			print_hesh();
		while (g_data.width-- > l)
			ft_printf_put_char('0');
	}
	else
	{
		while (g_data.width > l && g_data.width-- > g_data.precision)
			ft_printf_put_char(' ');
		if (g_data.specifier == 'p' || (g_data.flags[0] == '#' && h > 0))
			print_hesh();
	}
	while (g_data.precision-- > l)
		ft_printf_put_char('0');
	ft_printf_put_str(res);
}

static void		print(int l, char *res, __int128 h)
{
	if (g_data.flags[4] == '-')
	{
		if ((g_data.flags[0] == '#' && h > 0) || g_data.specifier == 'p')
		{
			print_hesh();
			g_data.width -= 2;
		}
		while (g_data.precision-- > l)
		{
			--g_data.width;
			ft_printf_put_char('0');
		}
		ft_printf_put_str(res);
		g_data.width -= l;
		while (g_data.width-- > 0)
			ft_printf_put_char(' ');
	}
	else
		print2(l, res, h);
}

void			print_hex(__int128 h)
{
	char		res[50];
	int			c;
	int			d;
	__int128	tmp;

	tmp = h;
	c = 0;
	if (!h && g_data.precision != 0)
		res[c++] = '0';
	while (h)
	{
		d = (h % 16);
		if (d > 9 && g_data.specifier == 'X')
			res[c++] = d + 'A' - 10;
		else if (d > 9 && (g_data.specifier == 'x' || g_data.specifier == 'p'))
			res[c++] = d + 'a' - 10;
		else
			res[c++] = d + '0';
		h /= 16;
	}
	res[c] = '\0';
	strrev(res);
	print(c, res, tmp);
}
