/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:07:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/23 09:12:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	add_start_room(t_lemin *lemin, t_rooms *room, char *in)
{
	while (!errno && (in = lemin_get_line()) && (ISCOMMENT(in) ||
			(ISCOMMAND(in) && ISSTART(in))))
		ft_strdel(&in);
	if (!in || (ISCOMMAND(in) && ISEND(in)))
		SETANDPERROR(5, "ERROR. No start room.");
	else if (!(room->name = valid_room_name(in)) && !errno)
		SETANDPERROR(5, "ERROR. Not valid start room name.");
	if (!errno)
		valid_room_coords(room, in);
	if (!errno)
		lemin->start_room = room;
	if (in)
		ft_strdel(&in);
	return (0);
}

static int	add_end_room(t_lemin *lemin, t_rooms *room, char *in)
{
	while (!errno && (in = lemin_get_line()) && (ISCOMMENT(in) ||
			(ISCOMMAND(in) && ISEND(in))))
		ft_strdel(&in);
	if (!in || (ISCOMMAND(in) && ISSTART(in)))
		SETANDPERROR(5, "ERROR. No end room.");
	else if (!(room->name = valid_room_name(in)) && !errno)
		SETANDPERROR(5, "ERROR. Not valid end room name.");
	if (!errno)
		valid_room_coords(room, in);
	if (!errno)
		lemin->end_room = room;
	if (in)
		ft_strdel(&in);
	return (0);
}

t_rooms		*add_start_end_rooms(t_lemin *lemin, t_rooms *rooms, char *in, int tp)
{
	if (!errno && lemin->start_room && tp == STARTROOM)
		SETANDPERROR(5, "ERROR. start room already available.");
	else if (!errno && lemin->end_room && tp == ENDROOM)
		SETANDPERROR(5, "ERROR. end room already available.");
	if (!errno && tp == STARTROOM)
		add_start_room(lemin, rooms, in);
	else if (!errno && tp == ENDROOM)
		add_end_room(lemin, rooms, in);
	return (rooms);
}
