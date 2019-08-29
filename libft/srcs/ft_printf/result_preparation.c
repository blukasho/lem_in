/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_preparation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:12:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				srcrpl(char *s, char a, char b)
{
	while (*s)
		if (*s++ == a)
			*(s - 1) = b;
	return (1);
}

void			result_preparation(va_list ap)
{
	if (g_data.specifier == 'd' || g_data.specifier == 'i')
		print_digits(ap);
	else if (g_data.specifier == 'u')
		print_unsigned_digits(ap);
	else if (g_data.specifier == 'o')
		print_octal(ap);
	else if (g_data.specifier == '%')
		print_percent(ap);
	else if (g_data.specifier == 'c')
		print_char(ap);
	else if (g_data.specifier == 's')
		print_string(ap);
	else if (g_data.specifier == 'x' || g_data.specifier == 'X')
		print_hexdecimal(ap);
	else if (g_data.specifier == 'p')
		print_pointer(ap);
	else if (g_data.specifier == 'f' || g_data.specifier == 'F')
		print_double(ap);
}
