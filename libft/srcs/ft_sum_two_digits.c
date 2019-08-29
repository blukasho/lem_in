/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_two_digits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:38:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/26 18:27:57 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_sum_two_digits	*init(int *a, int a_len, int b_len)
{
	t_sum_two_digits	*s;

	s = (t_sum_two_digits *)malloc(sizeof(t_sum_two_digits));
	ft_bzero(s, sizeof(t_sum_two_digits));
	s->r_len = a_len + b_len;
	s->r = (int *)malloc(s->r_len * sizeof(int));
	ft_bzero(s->r, s->r_len * sizeof(int));
	while (--a_len >= 0)
		s->r[a_len] = a[a_len];
	return (s);
}

t_sum_two_digits		*ft_sum_two_digits(int *a, int *b, int a_len, int b_len)
{
	t_sum_two_digits	*s;

	s = init(a, a_len, b_len);
	while (s->i < b_len)
	{
		s->r[s->i] = s->r[s->i] + b[s->i];
		if (s->r[s->i] > 9)
		{
			s->r[s->i + 1] = s->r[s->i + 1] + (s->r[s->i] / 10);
			s->r[s->i] = s->r[s->i] % 10;
		}
		++(s->i);
		while (s->r[s->i] > 10)
		{
			s->r[s->i + 1] = s->r[s->i + 1] + (s->r[s->i] % 10);
			s->r[s->i] = s->r[s->i] / 10;
		}
	}
	return (s);
}
