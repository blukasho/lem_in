/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:25:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/12 14:36:57 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = -1;
	if (sr < ds)
		while ((int)(--len) >= 0)
			ds[len] = sr[len];
	else
		while (++i < len)
			ds[i] = sr[i];
	return (dst);
}
