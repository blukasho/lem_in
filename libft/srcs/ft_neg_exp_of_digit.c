/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_exp_of_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/01 13:50:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_neg_exp_of_digit	*init(int dig, int base, int div)
{
	t_neg_exp_of_digit		*s;

	s = (t_neg_exp_of_digit *)malloc(sizeof(t_neg_exp_of_digit));
	ft_bzero(s, sizeof(t_neg_exp_of_digit));
	s->r_len = dig * (base + 1);
	s->r = (int *)malloc(s->r_len * sizeof(int));
	ft_bzero(s->r, s->r_len * sizeof(int));
	if (!base)
		s->r[0] = 1;
	s->div_len = div + 1;
	s->div = (int *)malloc(s->div_len * sizeof(int));
	ft_bzero(s->div, s->div_len * sizeof(int));
	s->per_len = MAX_PERIOD;
	s->per = (int *)malloc(s->per_len * sizeof(int));
	ft_bzero(s->per, s->per_len * sizeof(int));
	s->div[0] = 1;
	s->sw = 1;
	s->r_pos = 1;
	s->tmp = 1;
	return (s);
}

static t_sum_two_digits		*init_sum(void)
{
	t_sum_two_digits		*sum;

	sum = (t_sum_two_digits *)malloc(sizeof(t_sum_two_digits));
	ft_bzero(sum, sizeof(t_sum_two_digits));
	sum->r_len = 1;
	sum->r = (int *)malloc(sum->r_len * sizeof(int));
	ft_bzero(sum->r, sum->r_len * sizeof(int));
	return (sum);
}

static int					get_result_sum(int *a, int *b, int a_len, int b_len)
{
	int						r;
	t_sum_two_digits		*sum;
	t_sum_two_digits		*tmp;
	t_sum_two_digits		*tmp2;

	r = 0;
	sum = init_sum();
	while (ft_int_arr_comparing(a, sum->r, a_len, sum->r_len) == 1 && ++r)
	{
		tmp = sum;
		sum = ft_sum_two_digits(tmp->r, b, tmp->r_len, b_len);
		tmp2 = ft_sum_two_digits(sum->r, b, sum->r_len, b_len);
		if (ft_int_arr_comparing(a, tmp2->r, a_len, tmp2->r_len) == -1)
		{
			t_sum_two_digits_del(tmp);
			t_sum_two_digits_del(tmp2);
			t_sum_two_digits_del(sum);
			return (r);
		}
		t_sum_two_digits_del(tmp);
		t_sum_two_digits_del(tmp2);
	}
	return (0);
}

static void					get(t_neg_exp_of_digit *n, t_pos_exp_of_digit *p)
{
	t_int_arr_subtr			*m;
	int						i;

	while (ft_int_arr_comparing(n->div, p->r, n->div_len, p->r_len) >= 0)
	{
		i = 0;
		m = ft_int_arr_subtr(n->div, p->r, n->div_len, p->r_len);
		while (i < n->div_len)
			n->div[i++] = 0;
		while (m->r_len && m->r[--(m->r_len)] == 0)
			;
		while (m->r_len >= 0)
		{
			n->div[m->r_len] = m->r[m->r_len];
			--(m->r_len);
		}
		ft_memdel((void **)&m->r);
		ft_memdel((void **)&m);
	}
}

t_neg_exp_of_digit			*ft_neg_exp_of_digit(int dig, int base)
{
	t_neg_exp_of_digit		*neg;
	t_pos_exp_of_digit		*pos;

	base = -base;
	pos = ft_pos_exp_of_digit(dig, base);
	neg = init(dig, base, pos->r_len);
	while (base && srch_int_in_arr(neg->div, neg->div_len, 0))
	{
		while (ft_int_arr_comparing(neg->div, pos->r,
				neg->div_len, pos->r_len) == -1)
		{
			if (check_period(neg))
				return (neg);
			move_int_arr(neg->div, neg->div_len);
			if (ft_int_arr_comparing(neg->div, pos->r,
				neg->div_len, pos->r_len) == -1)
				neg->r[neg->r_pos++] = 0;
		}
		neg->r[neg->r_pos++] = get_result_sum(neg->div,
		pos->r, neg->div_len, pos->r_len);
		get(neg, pos);
	}
	ft_memdel((void **)&pos->r);
	ft_memdel((void **)&pos);
	return (neg);
}
