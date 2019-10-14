/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:21:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/14 12:29:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_index_room(t_rooms *rooms, int pos)
{
	while (rooms)
	{
		if (rooms->pos == pos)
			return (rooms->index);
		rooms = rooms->next;
	}
	return (0);
}

static int	check_need_count(t_rooms *rooms, int index, int pos)
{
	while (rooms && rooms->pos != pos)
		rooms = rooms->next;
	if (rooms)
	{
		if (rooms->index > index && !rooms->sw)
			return (1);
	}
	return (0);
}

static int	count_input_output_links(t_rooms *rooms, char **map,
			int index, int start)
{
	t_rooms	*curent_room;
	char	*room;

	curent_room = get_room(rooms, start);
	room = map[start];
	start = 0;
	while (room[start])
	{
		if (room[start] == SETCH && get_index_room(rooms, start) < index)
			++(curent_room->input_links);
		if (room[start] == SETCH && get_index_room(rooms, start) > index &&
			curent_room->type != ENDROOM)
			++(curent_room->output_links);
		++start;
	}
	curent_room->sw = 1;
	start = 0;
	while (room[start])
	{
		if (room[start] == SETCH && check_need_count(rooms, index, start))
			count_input_output_links(rooms, map, index + 1, start);
		++start;
	}
	return (0);
}

int			clear_parent_links(t_lemin *lemin)
{
	count_input_output_links(lemin->rooms, lemin->map, 0,
		lemin->start_room->pos);
	return (0);
}
