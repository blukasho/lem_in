/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_comparing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:07:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/30 16:44:33 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_int_arr_comparing(int *a, int *b, int a_len, int b_len)
{
	while (a_len && a[--a_len] == 0)
		;
	while (b_len && b[--b_len] == 0)
		;
	if (a_len > b_len)
		return (1);
	else if (a_len < b_len)
		return (-1);
	else
	{
		while (a_len >= 0)
		{
			if (a[a_len] > b[a_len])
				return (1);
			else if (a[a_len] < b[a_len])
				return (-1);
			--a_len;
		}
	}
	return (0);
}
