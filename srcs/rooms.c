/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:22:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/14 15:04:13 by blukasho         ###   ########.fr       */
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

static t_rooms	*add_room(t_rooms *rooms, char *input, int type)
{
	t_rooms		*tmp;

	tmp = NULL;
	if (!rooms)
		rooms = get_t_rooms(NULL);
	else
	{
		tmp = rooms;
		while (rooms->next)
			rooms = rooms->next;
		rooms->next = get_t_rooms(NULL);
		rooms = rooms->next;
	}
	rooms->type = type;
	if (!(rooms->name = valid_room_name(input)) && !errno && SETERRNO(5))
		perror("ERROR. rooms.c:valid_room_name().");
	if (!errno)
		valid_room_coords(rooms, input);
	return ((tmp ? tmp : rooms));
}

static t_rooms	*add_start_end_rooms(t_rooms *rooms, int type)
{
	char		*input;

	input = NULL;
	if (type == STARTROOM)
	{
		if (!(input = lemin_get_line()))
			SETANDPERROR(5, "ERROR. No start room.");
		else
			rooms = add_room(rooms, input, STARTROOM);
	}
	else if (type == ENDROOM)
	{
		if (!(input = lemin_get_line()))
			SETANDPERROR(5, "ERROR. No end room.");
		else
			rooms = add_room(rooms, input, ENDROOM);
	}
	if (input)
		ft_strdel(&input);
	return (rooms);
}

char			*get_rooms(t_lemin *lemin)
{
	t_rooms		*rooms;
	char		*input;

	rooms = lemin->rooms;
	while (!errno && (input = lemin_get_line()))
	{
		if (!errno && (ISCOMMENT(input) || (ISCOMMAND(input) && !ISSTART(input) && !ISEND(input))))
			ft_strdel(&input);
		else if (!errno && !rooms && ISCOMMAND(input) && ISSTART(input) && !ft_strdel(&input))
			rooms = add_start_end_rooms(rooms, STARTROOM);
		else if (!errno && rooms && ISCOMMAND(input) && ISEND(input) && !ft_strdel(&input))
			add_start_end_rooms(rooms, ENDROOM);
		else if (!errno && rooms)
			add_room(rooms, input, DEFAULTROOM);
		if (input)
			ft_strdel(&input);
	}
	if (!rooms)
		SETANDPERROR(5, "ERROR. No \"##start\" command.");
	else
		SETANDPERROR(5, "ERROR. No \"##end\" command.");
	if (input)
		ft_strdel(&input);
	return (rooms);
}
