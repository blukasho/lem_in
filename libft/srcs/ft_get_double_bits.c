/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_double_bits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:40:44 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/30 17:28:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bits			*ft_get_double_bits(long double ld)
{
	t_bits		*bits;
	__int128	li;
	int			i;

	li = *(__int128 *)&ld;
	bits = (t_bits *)malloc(sizeof(t_bits));
	ft_bzero(bits, sizeof(t_bits));
	i = 0;
	while (i <= 63)
	{
		if ((li & 0x1) == 1)
			bits->m[i++] = '1';
		else
			bits->m[i++] = '0';
		li = li >> 1;
	}
	bits->m[i] = '\0';
	bits->e = li & 0xFFFF;
	if (bits->e < 0)
		bits->e = bits->e ^ 0x8000;
	li = li >> 15;
	bits->s = li & 0x1;
	return (bits);
}
