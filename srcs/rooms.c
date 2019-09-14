/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:22:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/14 16:50:18 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		valid_room_coords(t_rooms *room, char *coords)
{
	if (!coords)
		SETANDPERROR(5, "ERROR. Broken coords.");
	if (!errno && (!(coords = ft_strchr(coords, ' ')) || (!ISDIGIT(*(++coords)) &&
		*coords != '-' && *coords != '+')))
		SETANDPERROR(5, "ERROR. Broken coord_x.");
	else if ((*coords == '-' || *coords == '+'))
		SETANDPERROR(5, "ERROR. Forbidden sign '+' or '-'");
	else if ((room->coord_x = ft_atoi(coords)) < 0)
		SETANDPERROR(5, "ERROR. Coords must be more or equal 0.");
	if (!errno)
		while (ISDIGIT(*coords))
			++coords;
	if (!errno && (!*coords || *(coords++) != ' '))
		SETANDPERROR(5, "ERROR. Broken coord_y.");
	else if (!ISDIGIT(*coords) && *coords != '-' && *coords != '+')
		SETANDPERROR(5, "ERROR. Broken coord_y.");
	else if (*coords == '-' || *coords == '+')
		SETANDPERROR(5, "ERROR. Forbidden sign '+' or '-'");
	else if ((room->coord_y = ft_atoi(coords)) < 0)
		SETANDPERROR(5, "ERROR. Coords must be more or equal 0.");
	if (!errno)
		while (ISDIGIT(*coords))
			++coords;
	if (!errno && *coords != 0)
		SETANDPERROR(5, "ERROR. Invalid input after coord_y.");
}

static char		*valid_room_name(char *name)
{
	char		*tmp;

	if (!name && SETERRNO(5))
		perror("ERROR. NULL room name.");
	if (!errno && *name == 'L' && SETERRNO(5))
		perror("ERROR. Room will never start with the character 'L'");
	if (!errno && (tmp = name))
	{
		while (*tmp && *tmp != ' ')
			if (*(tmp++) == '-')
				SETANDPERROR(5, "ERROR. Forbidden symbol '-' in room name.");
	}
	if (!errno && (ft_isalpha(*name) || ISDIGIT(*name)))
		return (ft_strndup(name, ft_strlen_chr(name, ' ')));
	return (NULL);
}

static t_rooms	*add_start_end_rooms(t_rooms *rooms, char *input, int type)
{
	while (!errno && (input = lemin_get_line()) && (ISCOMMENT(input) || ISCOMMAND(input)))
		ft_strdel(&input);
//	char		*input;
//
//	input = NULL;
//	if (type == STARTROOM)
//	{
//		if (!(input = lemin_get_line()))
//			SETANDPERROR(5, "ERROR. No start room.");
//		else
//			rooms = add_room(rooms, input, STARTROOM);
//	}
//	else if (type == ENDROOM)
//	{
//		if (!(input = lemin_get_line()))
//			SETANDPERROR(5, "ERROR. No end room.");
//		else
//			rooms = add_room(rooms, input, ENDROOM);
//	}
//	if (input)
//		ft_strdel(&input);
//	return (rooms);
}

static void		add_room(t_lemin *lemin, char *input, int type)
{
	t_rooms		*tmp;

	tmp = NULL;
	if (!(lemin->rooms))
		lemin->rooms = get_t_rooms(NULL);
	else
	{
		tmp = lemin->rooms;
		while (rooms->next)
			rooms = rooms->next;
		rooms->next = get_t_rooms(NULL);
		rooms = rooms->next;
	}
	rooms->type = type;
	if (type == STARTROOM)
		add_start_end_rooms(rooms, input, type);
	else if (type == ENDROOM)
		add_start_end_rooms(rooms, input, type);
	else if (!(rooms->name = valid_room_name(input)) && !errno && SETERRNO(5))
		perror("ERROR. rooms.c:valid_room_name().");
	if (!errno && type == DEFAULTROOM)
		valid_room_coords(rooms, input);
}

char			*get_rooms(t_lemin *lemin)
{
	char		*input;

	while (!errno && (input = lemin_get_line()))
	{
		if (!errno && (ISCOMMENT(input) || (ISCOMMAND(input) && !ISSTART(input)
			&& !ISEND(input))))
			ft_strdel(&input);
		else if (!errno && ISCOMMAND(input) && ISSTART(input) && !ft_strdel(&input))
			add_room(lemin, NULL, STARTROOM);
		else if (!errno && ISCOMMAND(input) && ISEND(input) && !ft_strdel(&input))
			add_room(lemin, NULL, ENDROOM);
		else if (!errno && !ISLINK(input))
			add_room(lemin, input, DEFAULTROOM);
		else if (!errno)
			return (input);
		if (input)
			ft_strdel(&input);
	}
//	if (!rooms)
//		SETANDPERROR(5, "ERROR. No \"##start\" command.");
//	else
//		SETANDPERROR(5, "ERROR. No \"##end\" command.");
	return (input);
}
