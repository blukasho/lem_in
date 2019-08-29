/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:18:59 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/12 14:36:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t destsize)
{
	const char	*sr;
	size_t		r;
	size_t		s;
	size_t		d;

	s = ft_strlen(src);
	d = ft_strlen(dst);
	sr = src;
	r = d;
	if (destsize < d)
		return (destsize + s);
	while (destsize - 1 > d && *sr)
	{
		dst[d] = *sr++;
		++d;
	}
	dst[d] = '\0';
	return (s + r);
}
