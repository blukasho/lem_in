/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 10:27:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/16 08:49:46 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*haystack)
	{
		while (needle[i] && haystack[i])
		{
			if (needle[i] != haystack[i])
				r = 1;
			i++;
		}
		if (r == 0)
			return ((char *)haystack);
		i = 0;
		r = 0;
		haystack++;
	}
	return (NULL);
}
