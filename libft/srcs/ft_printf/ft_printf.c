/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:11:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	g_print_symbols = 0;
	while (*format)
		if (*format == '%')
		{
			if (main_function(&format, ap) == -1)
				return (-1);
		}
		else
			ft_printf_put_char(*(format++));
	va_end(ap);
	return (g_print_symbols);
}
