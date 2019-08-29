/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:34:15 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/11 23:15:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1);
	res = (char *)malloc((++len + 1) * sizeof(char));
	if (res)
	{
		res[--len] = '\0';
		while ((int)(--len) >= 0)
			res[len] = s1[len];
		return (res);
	}
	return (NULL);
}
