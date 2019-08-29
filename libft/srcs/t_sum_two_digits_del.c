/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sum_two_digits_del.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:07:59 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/25 13:55:07 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	t_sum_two_digits_del(t_sum_two_digits *t)
{
	ft_memdel((void **)&t->r);
	ft_memdel((void **)&t);
}
