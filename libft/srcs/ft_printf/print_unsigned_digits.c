/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_digits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:25:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned_digits(va_list ap)
{
	g_data.flags[2] = -1;
	if (g_data.specifier == 'u' && !g_data.length
		&& srcrpl(g_data.flags, '+', -1))
		print_all_digits(va_arg(ap, unsigned int));
	else if (g_data.specifier == 'u' && g_data.length == 1
			&& srcrpl(g_data.flags, '+', -1))
		print_all_digits(va_arg(ap, unsigned long));
	else if (g_data.specifier == 'u' && g_data.length == 2
			&& srcrpl(g_data.flags, '+', -1))
		print_all_digits(va_arg(ap, unsigned long long));
	else if (g_data.specifier == 'u' && g_data.length == 4
			&& srcrpl(g_data.flags, '+', -1))
		print_all_digits((unsigned short)va_arg(ap, unsigned int));
	else if (g_data.specifier == 'u' && g_data.length == 5
			&& srcrpl(g_data.flags, '+', -1))
		print_all_digits((unsigned char)va_arg(ap, unsigned int));
}
