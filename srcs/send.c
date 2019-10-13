/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:18:02 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/13 22:06:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static char	*get_name_room(t_rooms *rooms, int pos, int *type)
{
	while (rooms)
	{
		if (rooms->pos == pos)
		{
			*type = rooms->type;
			return (rooms->name);
		}
		rooms = rooms->next;
	}
	return (NULL);
}

static int	prepare_ways(t_way **ways, t_rooms *rooms)
{
	t_way	*way;

	while (*ways)
	{
		way = *ways;
		while (way)
		{
			way->name = get_name_room(rooms, way->pos, &(way->type));
			way = way->next;
		}
		++ways;
	}
	return (0);
}

static int	move_ants(t_way *way, int ant)
{
	int		tmp;

	tmp = way->ant;
	way->ant = ant;
	if (way->next)
		move_ants(way->next, tmp);
	return (0);
}

static int	print_ways(t_way **ways, int out)
{
	int		enter;
	t_way	*way;

	enter = 0;
	while (*ways)
	{
		way = *ways;
		while (way)
		{
			if (way->ant && (enter = 1) && out)
				ft_printf("L%d-%s ", way->ant, way->name);
			way = way->next;
		}
		++ways;
	}
	if (enter && out)
		ft_printf("\n");
	return ((enter ? 1 : 0));
}

int			send_ants(t_lemin *lemin, int out)
{
	int		send_ants;
	int		remainng_ants;
	t_way	**ways;

	send_ants = 1;
	remainng_ants = lemin->ants;
	prepare_ways(lemin->ways, lemin->rooms);
	while (1 && (ways = lemin->ways))
	{
		while (*ways)
		{
			move_ants((*ways)->next, send_ants);
			if (remainng_ants)
			{
			   	++send_ants;
				--remainng_ants;
			}
			if (!remainng_ants)
				send_ants = 0;
			++ways;
		}
		if (!print_ways(lemin->ways, out))
			return (0);
	}
	return (0);
}
