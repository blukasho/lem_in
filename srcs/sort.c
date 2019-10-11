/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:07:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/11 08:49:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int			count_links(t_way *way, char **map)
{
	char	*room_links;
	int		links;

	links = 0;
	while (way->next)
		way = way->next;
	room_links = map[way->pos];
	while (*room_links)
	{
		if (*room_links == SETCH)
			++links;
		++room_links;
	}
	return (links);
}

int				sort_ways(t_way **ways, char **map)
{               
	int			y;
	int			x;
	t_way		*tmp;

	y = 0;
	while (ways[y])
	{
		x = y + 1;	
		while (ways[x])
		{
			if (count_links(ways[y], map) > count_links(ways[x], map))
			{
				tmp = ways[y];
				ways[y] = ways[x];
				ways[x] = tmp;
			}
			++x;
		}
		++y;
	}
	return (0);
}
