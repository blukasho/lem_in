/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:52:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print(char *s, int len, int prs)
{
	if (ft_strchr(g_data.flags, '-'))
	{
		while (*s && prs--)
			ft_printf_put_char(*(s++));
		while (g_data.width-- > len)
			ft_printf_put_char(' ');
	}
	else
	{
		if (!ft_strchr(g_data.flags, '0'))
		{
			while (g_data.width-- > len)
				ft_printf_put_char(' ');
			while (*s && prs--)
				ft_printf_put_char(*(s++));
		}
		else
		{
			while (g_data.width-- > len)
				ft_printf_put_char('0');
			while (*s && prs--)
				ft_printf_put_char(*(s++));
		}
	}
}

void			print_s(char *s)
{
	int			len;
	int			prs;

	len = ft_strlen(s);
	prs = len;
	if ((g_data.precision >= 0) && (g_data.precision < len))
	{
		len = g_data.precision;
		prs = len;
	}
	if (g_data.width > len)
		print(s, len, prs);
	else
		while (*s && prs--)
			ft_printf_put_char(*(s++));
}

void			print_string(va_list ap)
{
	char		*s;

	s = va_arg(ap, char *);
	if (!s)
		print_s("(null)");
	else
		print_s(s);
}
