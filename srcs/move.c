/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:09:50 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/14 12:34:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	way_len(t_way *way)
{
	int		len;

	len = 0;
	while (way && ++len)
		way = way->next;
	return (len);
}

int			check_move(t_way **all_ways, t_way **now_way, int ants)
{
	int		result;

	if ((*all_ways)->next == (*now_way)->next)
		return (1);
	result = way_len(*now_way) - 1;
	++all_ways;
	while ((*all_ways)->next != (*now_way)->next)
	{
		result += way_len(*now_way) - way_len(*all_ways);
		++all_ways;
	}
	return (((ants - 1) > result ? 1 : 0));
}
