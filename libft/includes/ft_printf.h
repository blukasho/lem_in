/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:49:24 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/01 13:50:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# define MAX_EXP 32767

int				g_print_symbols;

typedef struct	s_data
{
	char		flags[5];
	long		width;
	long		precision;
	char		length;
	char		specifier;
}				t_data;

t_data			g_data;

int				ft_printf(const char *format, ...);
int				ft_get_real_len(int *a, int a_len);
int				ft_is_neg_inf(t_double_res *d);
int				ft_is_pos_inf(t_double_res *d);
int				ft_is_nan(t_double_res *d);
int				ft_len_nbr(__int128 d);
int				srcrpl(char *s, char a, char b);
int				main_function(const char **format, va_list ap);
int				check_errors(void);
int				print_nan(t_double_res *d);
int				print_inf(t_double_res *d);
void			move_int_arr(int *a, int a_len);
void			print_t_double(t_double_res *r);
void			print_precision_octal(int l);
void			print_width_octal(char c);
void			print_percent(va_list ap);
void			print_double(va_list ap);
void			print_hexdecimal(va_list ap);
void			print_hex(__int128 h);
void			print_all_digits(__int128 d);
void			print_unsigned_digits(va_list ap);
void			print_hesh(void);
void			print_octal(va_list ap);
void			ft_printf_put_str(char *s);
void			ft_printf_put_char(char c);
void			print_digits(va_list ap);
void			print_pointer(va_list ap);
void			print_string(va_list ap);
void			print_char(va_list ap);
void			print_s(char *s);
void			print_c(int c);
void			result_preparation(va_list ap);
void			parse_format_specifiers(const char **format);
void			parse_flags(const char **format);
void			round_double(t_double_res *d);
#endif
