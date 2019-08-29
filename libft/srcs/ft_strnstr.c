/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:30:14 by blukasho          #+#    #+#             */
/*   Updated: 2019/01/12 14:37:01 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		r;

	i = 0;
	r = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*haystack && len >= ft_strlen(needle))
	{
		while (needle[i])
		{
			if (needle[i] != haystack[i])
				r = 1;
			i++;
		}
		if (r == 0)
			return ((char *)haystack);
		len--;
		i = 0;
		r = 0;
		haystack++;
	}
	return (NULL);
}
