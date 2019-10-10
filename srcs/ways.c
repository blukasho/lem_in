/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:17:55 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/10 12:36:30 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		add_way_to_turn(t_lemin *lemin, int start)
{
	t_way		*new_way;

	new_way = cp_way_add_room(*(lemin->turn), start);
	lemin->turn = add_way_to_ways(lemin->turn, new_way);
	return (0);
}

static int		get_start(t_way *way)
{
	if (way)
	{
		while (way->next)
			way = way->next;
		return (way->pos);
	}
	return (0);
}

static int		skip_way(t_way **ways)
{
	while (*(ways + 1))
	{
		*ways = *(ways + 1);
		++ways;
	}
	*ways = NULL;
	return (0);
}

static int		check_errors_and_find_end(t_lemin *lemin)
{
	t_way		**ways;

	ways = lemin->turn;
	if (!ways || !*ways)
		return (0);
	clear_way(*ways);
	skip_way(ways);
	while (*ways)
	{
		if (check_duplicates(*ways) && !clear_way(*ways))
			skip_way(ways);
		else if (check_final_way(lemin->end_room, *ways) && (lemin->ways = add_way_to_ways(lemin->ways, *ways)))
			skip_way(ways);
		else
			++ways;
	}
	return (0);
}

int				lemin_find_ways(t_lemin *lemin)
{
	int			start;
	char		*room;

	start = lemin->start_room->pos;
	if (lemin->turn)
	{
		if (errno)
			return (0);
		start = get_start(*(lemin->turn));
		room = (lemin->map)[start];
		start = 0;
		while (room[start])
		{
			if (room[start] == SETCH)
				add_way_to_turn(lemin, start);
			++start;
		}
//		print_final_ways(lemin->turn);
		check_errors_and_find_end(lemin);
		if (!*(lemin->turn))
			return (0);
	}
	else
	{
		lemin->turn = add_way_to_ways(NULL, add_room_to_way(NULL, start));
//		print_final_ways(lemin->turn);
	}
	return (1);
}
