/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:22:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/06 10:12:09 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

//static void		*valid_room_coords(t_room *room, char *coords)
//{
//	while (ft_isalpha(*tmp) || ft_isdigit(*tmp))
//		++tmp;
//	if ((!*tmp || *tmp != ' ') && SETERRNO(5))
//		perror("ERROR. Wrong coord.");
//	else if (
//
//}

static char		*valid_room_name(char *name)
{
	if (!name && SETERRNO(5))
		perror("ERROR. NULL room name.");
	if (!errno && *name == 'L' && SETERRNO(5))
		perror("ERROR. Room will never start with the character 'L'");
	if (!errno && ft_strchr(name, '-') && SETERRNO(5))
		perror("ERROR. Forbidden symbol '-' in room name.");
	else if (!errno && (ft_isalpha(*name) || ft_isdigit(*name)))
		return (ft_strndup(name, ft_strlen_chr(name, ' ')));
	return (NULL);
}

static t_rooms	*add_room(t_rooms *rooms, char *input, int type)
{
	if (!rooms)
		rooms = get_t_rooms(NULL);
	rooms->type = type;
	if (!(rooms->name = valid_room_name(input)) && !errno && SETERRNO(5))
		perror("ERROR. rooms.c:valid_room_name().");
	return (rooms);
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
		else if (SETERRNO(5))
			perror("ERROR. No \"##start\" command.");
	}
	return (rooms);
}
