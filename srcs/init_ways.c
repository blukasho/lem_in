/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:35:56 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/04 21:03:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	count_ways(t_way **ways)
{
	int		len;

	len = 0;
	while (*ways && ++len)
		++ways;
	return (len);
}

t_way		**add_way_to_ways(t_way **ways, t_way *way)
{
	t_way	**tmp;
	int		i;

	if ((i = 1) && way)
		++i;
	if (ways)
	{
		tmp = ways;
		ways = (t_way **)malloc((count_ways(ways) + i) * sizeof(t_way *));
		i = ~0;
		while (tmp[++i])
			ways[i] = tmp[i];
		if (way && ++i)
			ways[i] = tmp[i];
		ways[++i] = NULL;
		free(tmp);

	}
	else if ((ways = (t_way **)malloc(i * sizeof(t_way *))))
	{
		if (--i && way)
			*ways = way;
		*(ways + i) = NULL;
	}
	return (ways);
}

