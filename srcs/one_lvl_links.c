/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_lvl_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:38:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/12 01:24:30 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	get_index(t_rooms *rooms, int pos)
{
	while (rooms)
	{
		if (rooms->pos == pos)
			return (rooms->index);
		rooms = rooms->next;
	}
	return (0);
}

int			clear_one_lvl_links(t_lemin *lemin)
{
	char	**map;
	int		filial;
	int		parent;


	map = lemin->map;
	parent = 0;
	while (map[parent])
	{
		filial = 0;
		while (map[parent][filial])
		{
			if (map[parent][filial] == SETCH && get_index(lemin->rooms, parent) == get_index(lemin->rooms, filial))
			{
				map[parent][filial] = FILLCH;
//				ft_printf("y_room |%d| x_room |%d|\n", parent, filial);
			}
			++filial;
		}
		++parent;
	}
	return (0);
}
