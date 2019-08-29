/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_del_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:37:42 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/11 14:42:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_del_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*arr)
		ft_strdel(&(*(arr++)));
	free(tmp);
	return (0);
}
