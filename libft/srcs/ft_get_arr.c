/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:50:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/16 09:00:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_get_arr(int x, int y)
{
	char	**res;
	int		i;

	i = 0;
	if ((res = (char **)malloc((y + 1) * sizeof(char *))))
	{
		while (i < y)
			res[i++] = ft_strnew(x);
		res[i] = NULL;
	}
	return (res);
}
