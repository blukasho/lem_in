/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:25:18 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 17:43:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = NULL;
	str = (char *)ft_memalloc(++size);
	if (str)
		ft_memset(str, '\0', size);
	return (str);
}
