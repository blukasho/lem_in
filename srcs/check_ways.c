/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:59:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/07 21:05:39 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			check_duplicates(t_way *way)
{
	t_way	*inside_way;

	while (way && way->next)
	{
		inside_way = way->next;
		while (inside_way)
		{
			if (way->pos == inside_way->pos)
				return (1);
			inside_way = inside_way->next;
		}
		way = way->next;
	}
	return (0);
}

int		check_final_way(t_rooms *end, t_way *way)
{
	while (way)
	{
		if (way->pos == end->pos)
			return (1);
		way = way->next;
	}
	return (0);
}
