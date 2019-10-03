/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:42:02 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/03 19:32:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static const char	*check_sign(const char *str, int *min)
{
	if (*str == '-')
		(*min)++;
	if (*str == '+' || *str == '-')
		++str;
	return ((const char *)str);
}

static const char	*check_sp(const char *str)
{
	while ((*str >= 1 && *str <= 19) || *str == 32)
		++str;
	return ((const char *)str);
}

long long int		ft_atoi(const char *nptr)
{
	long long int	res;
	int				min;

	min = 0;
	res = 0;
	nptr = check_sp(nptr);
	nptr = check_sign(nptr, &min);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (9223372036854775807 - res < *nptr - 48)
			return ((!min ? -1 : 0));
		res = (res * 10) + (*nptr++ - 48);
	}
	if (min == 1)
		res *= -1;
	return (res);
}
