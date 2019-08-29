/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:46:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 19:09:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		skip_digits(const char **format)
{
	while (ft_isdigit(**format))
		++(*(format));
}

static void		get_length(const char **format)
{
	if (!ft_strncmp(*format, "ll", 2) && (g_data.length = 2))
		*format += 2;
	else if (!ft_strncmp(*format, "hh", 2) && (g_data.length = 5))
		*format += 2;
	else if (!ft_strncmp(*format, "l", 1) && (g_data.length = 1))
		++(*(format));
	else if (!ft_strncmp(*format, "h", 1) && (g_data.length = 4))
		++(*(format));
	else if (!ft_strncmp(*format, "L", 1) && (g_data.length = 3))
		++(*(format));
}

static void		get_specifier(const char **format)
{
	if ((**format == 'd' || **format == 'i' || **format == 'o'
		|| **format == 'u' || **format == 'x' || **format == 'x'
		|| **format == 'X' || **format == 'f' || **format == '%'
		|| **format == 'c' || **format == 's' || **format == 'p'
		|| **format == 'F')
		&& (g_data.specifier = **format))
		++(*(format));
}

void			parse_format_specifiers(const char **format)
{
	g_data = (t_data)
	{{-1, -1, -1, -1, -1}, -1, -1, 0, -1};
	parse_flags(format);
	g_data.width = ft_atoi(*format);
	if (g_data.width > -1)
		skip_digits(format);
	if (**format == '.')
	{
		g_data.precision = ft_atoi(++(*(format)));
		skip_digits(format);
	}
	get_length(format);
	get_specifier(format);
}
