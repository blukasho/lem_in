/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:22:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/19 14:04:38 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void		valid_room_coords(t_rooms *room, char *coords)
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
	else if (!errno && !ISDIGIT(*coords) && *coords != '-' && *coords != '+')
		SETANDPERROR(5, "ERROR. Broken coord_y.");
	else if (!errno && (*coords == '-' || *coords == '+'))
		SETANDPERROR(5, "ERROR. Forbidden sign '+' or '-'");
	else if (!errno && (room->coord_y = ft_atoi(coords)) < 0)
		SETANDPERROR(5, "ERROR. Coords must be more or equal 0.");
	if (!errno)
		while (ISDIGIT(*coords))
			++coords;
	if (!errno && *coords != 0)
		SETANDPERROR(5, "ERROR. Invalid input after coord_y.");
}

char			*valid_room_name(char *name)
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

static void		add_room(t_lemin *lemin, char *input, int type)
{
	t_rooms		*tmp;

	tmp = NULL;
	if (!(lemin->rooms))
	{
		lemin->rooms = get_t_rooms(NULL);
		tmp = lemin->rooms;
	}
	else
	{
		tmp = lemin->rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = get_t_rooms(NULL);
		tmp = tmp->next;
	}
	tmp->type = type;
	if (type == STARTROOM)
		add_start_end_rooms(lemin, tmp, input, type);
	else if (type == ENDROOM)
		add_start_end_rooms(lemin, tmp, input, type);
	else if (!(tmp->name = valid_room_name(input)) && !errno && SETERRNO(5))
		perror("ERROR. rooms.c:valid_room_name().");
	if (!errno && type == DEFAULTROOM)
		valid_room_coords(tmp, input);
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
		{
			if (!lemin->start_room)
				SETANDPERROR(5, "ERROR. No \"##start\" command.");
			else if (!lemin->end_room)
				SETANDPERROR(5, "ERROR. No \"##end\" command.");
			return (input);
		}
		if (input)
			ft_strdel(&input);
	}
	if (!errno && !lemin->rooms)
		SETANDPERROR(5, "ERROR. No rooms.");
	return (input);
}
