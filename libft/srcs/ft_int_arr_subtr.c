/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_subtr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:57:27 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/27 11:32:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_int_arr_subtr	*init(int *a, int *b, int a_len, int b_len)
{
	t_int_arr_subtr		*s;

	s = (t_int_arr_subtr *)malloc(sizeof(t_int_arr_subtr));
	ft_bzero(s, sizeof(t_int_arr_subtr));
	s->r_len = a_len + b_len;
	s->r = (int *)malloc(s->r_len * sizeof(int));
	ft_bzero(s->r, s->r_len * sizeof(int));
	while (s->count < a_len)
	{
		s->r[s->count] = a[s->count];
		++(s->count);
	}
	s->count = 0;
	s->r_a_len = a_len;
	s->r_b_len = b_len;
	while (a[--(s->r_a_len)] == 0)
		;
	while (b[--(s->r_b_len)] == 0)
		;
	return (s);
}

t_int_arr_subtr			*ft_int_arr_subtr(int *a, int *b, int a_len, int b_len)
{
	t_int_arr_subtr		*s;

	s = init(a, b, a_len, b_len);
	while (s->count <= s->r_b_len)
	{
		if (s->r[s->count] >= b[s->count])
			s->r[s->count] = (s->r[s->count]) - (b[s->count]);
		else
		{
			s->find = s->count + 1;
			while (s->r[s->find] == 0 && s->find < s->r_a_len)
				s->r[s->find++] = 9;
			--(s->r[s->find]);
			s->r[s->count] = (s->r[s->count] + 10) - b[s->count];
		}
		++(s->count);
	}
	return (s);
}
