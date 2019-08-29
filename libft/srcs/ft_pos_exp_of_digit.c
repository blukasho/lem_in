/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_exp_of_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:07:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/26 18:29:50 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_pos_exp_of_digit	*init(int dig, int base)
{
	t_pos_exp_of_digit		*s;

	s = (t_pos_exp_of_digit *)malloc(sizeof(t_pos_exp_of_digit));
	ft_bzero(s, sizeof(t_pos_exp_of_digit));
	s->r_len = base * ft_len_of_digit(dig) + 1;
	s->r = (int *)malloc(s->r_len * sizeof(int));
	ft_bzero(s->r, s->r_len * sizeof(int));
	s->r[0] = 1;
	return (s);
}

t_pos_exp_of_digit			*ft_pos_exp_of_digit(int dig, int base)
{
	t_pos_exp_of_digit		*s;

	s = init(dig, base);
	if (!base)
		return (s);
	while (base-- > 0)
	{
		s->i = 0;
		while (s->i < s->r_len)
		{
			s->r[s->i] = s->r[s->i] * dig;
			++(s->i);
		}
		s->i = 0;
		while (s->i < s->r_len)
		{
			if (s->r[s->i] > 9)
			{
				s->r[s->i + 1] = s->r[s->i + 1] + (s->r[s->i] / 10);
				s->r[s->i] = s->r[s->i] % 10;
			}
			++(s->i);
		}
	}
	return (s);
}
