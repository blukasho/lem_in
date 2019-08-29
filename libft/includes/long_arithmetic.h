/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:15:28 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/01 14:42:10 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_ARITHMETIC_H
# define LONG_ARITHMETIC_H
# include "libft.h"

# define MAX_PERIOD 100

typedef struct		s_neg_exp_of_digit
{
	int				tmp;
	int				sw;
	int				*r;
	int				r_pos;
	int				r_len;
	int				*div;
	int				div_len;
	int				*per;
	int				per_len;
}					t_neg_exp_of_digit;

typedef struct		s_pos_exp_of_digit
{
	int				i;
	int				r_len;
	int				*r;
}					t_pos_exp_of_digit;

typedef struct		s_sum_two_digits
{
	int				i;
	int				r_len;
	int				*r;
}					t_sum_two_digits;

typedef struct		s_int_arr_subtr
{
	int				flag;
	int				find;
	int				count;
	int				r_a_len;
	int				r_b_len;
	int				r_len;
	int				*r;
}					t_int_arr_subtr;

typedef struct		s_int_arr_mult
{
	int				*r;
	int				a_tmp;
	int				b_tmp;
	int				r_len;
}					t_int_arr_mult;

t_sum_two_digits	*ft_sum_two_digits(int *a, int *b, int a_len, int b_len);
t_int_arr_subtr		*ft_int_arr_subtr(int *a, int *b, int a_len, int b_len);
t_int_arr_mult		*ft_int_arr_mult(int *a, int *b, int a_len, int b_len);
t_neg_exp_of_digit	*ft_sum(t_neg_exp_of_digit *a, t_neg_exp_of_digit *b);
t_neg_exp_of_digit	*ft_neg_exp_of_digit(int dig, int base);
t_pos_exp_of_digit	*ft_pos_exp_of_digit(int dig, int base);

int					check_period(t_neg_exp_of_digit *neg);

#endif
