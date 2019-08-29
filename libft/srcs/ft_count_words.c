/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:10:27 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/12 01:18:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t res;

	res = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			while (*s && *s != c)
				s++;
			res++;
		}
		if (*s)
			s++;
	}
	return (res);
}
