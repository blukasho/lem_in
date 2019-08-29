/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:18:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(va_list ap)
{
	print_c(va_arg(ap, int));
}

void		print_c(int c)
{
	if (g_data.width > 1 && ft_strchr(g_data.flags, '-'))
	{
		ft_printf_put_char(c);
		while (g_data.width-- > 1)
			ft_printf_put_char(' ');
	}
	else
	{
		if (!ft_strchr(g_data.flags, '0'))
			while (g_data.width-- > 1)
				ft_printf_put_char(' ');
		else
			while (g_data.width-- > 1)
				ft_printf_put_char('0');
		ft_printf_put_char(c);
	}
}
