/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:22:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/06 11:28:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		valid_room_coords(t_rooms *room, char *coords)
{
	if (!(coords = ft_strchr(coords, ' ')) || (!ft_isdigit(*(++coords)) &&
		*coords != '-' && *coords != '+'))
		SETANDPERROR(5, "ERROR. Broken coord_x.");
	if (coords && (*coords == '-' || *coords == '+'))
		SETANDPERROR(5, "ERROR. Forbidden sign '+' or '-'");
	if (!errno && (room->coord_x = ft_atoi(coords)) < 0)
		SETANDPERROR(5, "ERROR. Coords must be more or equal 0.");
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
	if (!errno && (ft_isalpha(*name) || ft_isdigit(*name)))
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
	}
	rooms->type = type;
	if (!(rooms->name = valid_room_name(input)) && !errno && SETERRNO(5))
		perror("ERROR. rooms.c:valid_room_name().");
	if (!errno)
		valid_room_coords(rooms, input);
	return ((tmp ? tmp : rooms));
}

t_rooms		*get_rooms(void)
{
	t_rooms	*rooms;
	char	*input;

	rooms = NULL;
	while (!errno && (input = lemin_get_line()))
	{
		if (!errno && (ISCOMMENT(input) || (ISCOMMAND(input) && !ISSTART(input))))
			ft_strdel(&input);
		else if (!errno && ISCOMMAND(input) && ISSTART(input) && !ft_strdel(&input))
			rooms = add_room(rooms, lemin_get_line(), STARTROOM);
//test arch
		else
			SETANDPERROR(5, "ERROR. No \"##start\" command.");
	}
	return (rooms);
}
