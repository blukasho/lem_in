/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:20:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:08:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format_symbol(char c)
{
	return ((c == '#' || c == '0' || c == ' ' || c == '+' || c == '-' ? 1 : 0));
}

void		parse_flags(const char **format)
{
	if (**format == '%')
		++(*(format));
	while (check_format_symbol(**format))
		if (**format == '#' && (g_data.flags[0] = '#'))
			++(*format);
		else if (**format == '0' && (g_data.flags[1] = '0'))
			++(*format);
		else if (**format == ' ' && (g_data.flags[2] = ' '))
			++(*format);
		else if (**format == '+' && (g_data.flags[3] = '+'))
			++(*format);
		else if (**format == '-' && (g_data.flags[4] = '-'))
			++(*format);
}
