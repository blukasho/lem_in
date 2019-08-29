/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:41:21 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/12 14:36:58 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src)
		if (*src++ == c)
			return ((char *)--src);
	if (*src == c)
		return ((char *)src);
	return (NULL);
}
