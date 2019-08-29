/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:40:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/28 21:38:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_int_arr_mult	*init(int a_len, int b_len)
{
	t_int_arr_mult		*s;

	s = (t_int_arr_mult *)malloc(sizeof(t_int_arr_mult));
	ft_bzero(s, sizeof(t_int_arr_mult));
	s->r_len = a_len + b_len + 2;
	s->r = (int *)malloc(s->r_len * sizeof(int));
	ft_bzero(s->r, s->r_len * sizeof(int));
	return (s);
}

t_int_arr_mult			*ft_int_arr_mult(int *a, int *b, int a_len, int b_len)
{
	t_int_arr_mult		*s;

	s = init(a_len, b_len);
	while (a[--a_len] == 0)
		;
	while (b[--b_len] == 0)
		;
	while (s->a_tmp <= a_len)
	{
		s->b_tmp = -1;
		while (++(s->b_tmp) <= b_len)
			s->r[s->a_tmp + s->b_tmp] += a[s->a_tmp] * b[s->b_tmp];
		++(s->a_tmp);
	}
	a_len = -1;
	while (++a_len < (s->r_len - 1))
	{
		s->r[a_len + 1] += s->r[a_len] / 10;
		s->r[a_len] %= 10;
	}
	return (s);
}
