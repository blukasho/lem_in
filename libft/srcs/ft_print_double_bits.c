/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_bits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:49:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/29 17:01:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_print_double_bits(long double d)
{
	int			i;
	char		b[81];
	__int128	li;

	li = *(__int128 *)&d;
	i = 0;
	while (i <= 80)
	{
		if ((li & 0x1) == 1)
			b[i] = '1';
		else
			b[i] = '0';
		++i;
		li = li >> 1;
	}
	b[i] = '\0';
	i = 79;
	while (i >= 0)
		ft_printf("%c", b[i--]);
	ft_printf("\n");
}
