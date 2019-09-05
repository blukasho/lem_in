/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:22:27 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/05 08:58:35 by blukasho         ###   ########.fr       */
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
	if (name)
		room->name = name;
	return (room);
}
