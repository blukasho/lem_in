/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:17:55 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/07 15:58:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				lemin_find_ways(t_lemin *lemin)
{
	int			start;
	char		**map;
	t_way		*way;

	map = lemin->map;
	if (map)
	{}
	start = lemin->start_room->pos;
	if (!(way = NULL) && lemin->ways)
	{
	}
	else
	{
		lemin->ways = add_way_to_ways(NULL, add_room_to_way(NULL, start));
		return (1);
	}
	return (0);
}
