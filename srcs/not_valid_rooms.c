/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_valid_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:35:05 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/12 02:35:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	check_bad_link(t_rooms *rooms, int pos)
{
	while (rooms && rooms->pos != pos)
		rooms = rooms->next;
	if (rooms && rooms->type == DEFAULTROOM)
	{
		if (rooms->input_links == 0)
			return (1);
		if (rooms->output_links == 0)
			return (1);
		if (rooms->index == -1)
			return (1);
	}
	return (0);
}

int			clear_not_valid_rooms(t_lemin *lemin)
{
	char	**map;
	int		room;
	int		layer;

	layer = 0;
	map = lemin->map;
	while (map[layer])
	{
		room = 0;
		while (map[layer][room])
		{
			if (map[layer][room] == SETCH && check_bad_link(lemin->rooms, room))
			{
				ft_printf("y |%d| x |%d|\n", layer, room);
				map[layer][room] = FILLCH;
				map[room][layer] = FILLCH;
			}
			++room;
		}
		++layer;
	}
	return (0);
}
