/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:17:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/11 21:04:14 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static t_rooms	*find_room(int room_pos, t_rooms *rooms)
{
	while (rooms->pos != room_pos)
		rooms = rooms->next;
	if (rooms && (rooms->index) == -1)
		return (rooms);
	return (NULL);
}

int			check_lvl(t_rooms *rooms, int pos_a, int pos_b)
{
	int		index_a;
	int		index_b;

	index_a = -1;
	index_b = -1;
	while (rooms)
	{
		if (rooms->pos == pos_a)
			index_a = rooms->index;
		else if (rooms->pos == pos_b)
			index_b = rooms->index;
		rooms = rooms->next;
	}
	if (index_b > index_a)
		return (1);
	return (0);
}

static int	find_end_and_set_index(t_rooms *rooms)
{
	while (rooms)
	{
		if (rooms->type == STARTROOM)
			rooms->index = 0;
		if (rooms->type == ENDROOM)
			rooms->index = INT_MAX;
		rooms = rooms->next;
	}
	return (0);
}

int			indexation_lvl(t_rooms *rooms, char **map, int start, int index)
{
	char	*lvl;
	t_rooms	*room;

	lvl = map[start];
	start = 0;
	find_end_and_set_index(rooms);
	while (lvl[start])
	{
		if (lvl[start] == SETCH)
		{
			room = find_room(start, rooms);
			if (room)
			{
				room->index = index;
				indexation_lvl(rooms, map, start, index + 1);
			}
		}
		++start;
	}
	return (0);
}
