/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:22:27 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/13 14:43:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_lemin		*get_t_lemin(void)
{
	t_lemin	*lemin;

	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	ft_bzero(lemin, sizeof(t_lemin));
	return (lemin);
}

t_rooms		*get_t_rooms(char *name)
{
	t_rooms	*room;

	room = (t_rooms *)malloc(sizeof(t_rooms));
	ft_bzero(room, sizeof(t_rooms));
	room->index = -1;
	if (name)
		room->name = name;
	return (room);
}

t_way		*get_t_way(int pos)
{
	t_way	*way;

	way = (t_way *)malloc(sizeof(t_way));
	ft_bzero(way, sizeof(t_way));
	way->pos = pos;
	return (way);
}
