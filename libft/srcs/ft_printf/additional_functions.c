/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:10:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_printf_put_char(char c)
{
	write(1, &c, 1);
	++g_print_symbols;
}

void				ft_printf_put_str(char *s)
{
	while (*s)
		ft_printf_put_char(*(s++));
}

void				print_hesh(void)
{
	if (g_data.specifier == 'o')
		ft_printf_put_char('0');
	else if (g_data.specifier == 'x' || g_data.specifier == 'p')
		ft_printf_put_str("0x");
	else if (g_data.specifier == 'X')
		ft_printf_put_str("0X");
}

int					ft_get_real_len(int *a, int a_len)
{
	while (a_len > 0 && a[--a_len] == 0)
		;
	return (a_len);
}
