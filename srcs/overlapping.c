/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:55:05 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/13 18:17:51 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	check_overlapping(t_way *way_one, t_way *way_two)
{
	int		overlapping;
	t_way	*tmp;

	overlapping = 0;
	tmp = way_two;
	while (way_one)
	{
		way_two = tmp;
		while (way_two)
		{
			if (way_one->pos == way_two->pos)
				++overlapping;
			way_two = way_two->next;
		}
		way_one = way_one->next;
	}
	return ((overlapping > 2 ? 1 : 0));
}

static int	delete_way(t_way **ways)
{
	clear_way(*ways);
	while (*ways)
	{
		*ways = *(ways + 1);
		++ways;
	}
	return (0);
}

int			clear_overlapping(t_lemin *lemin)
{
	t_way	**ways;
	t_way	**inside_ways;

	ways = lemin->ways;
	while (*ways)
	{
		inside_ways = ways + 1;
		while (*inside_ways)
		{
			if (check_overlapping(*ways, *inside_ways))
				delete_way(inside_ways);
			else
				++inside_ways;
		}
		++ways;
	}
	return (0);
}
