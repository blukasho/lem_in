/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:20:18 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/03 11:24:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	links_prepare_to_read(t_lemin *lemin)
{
	int		size_one_side;
	int		counter;
	char	**graph_map;
	t_rooms	*rooms;

	size_one_side = get_len_rooms(lemin->rooms);
	graph_map = (char **)malloc(++size_one_side * sizeof(char *));
	counter = size_one_side - 1;
	graph_map[counter] = NULL;
	while (--counter >= 0)
	{
		graph_map[counter] = ft_memset((char *)malloc(size_one_side *
		sizeof(char)), FILLCH, size_one_side);
		graph_map[counter][size_one_side - 1] = 0;
	}
	lemin->map = graph_map;
	counter = 0;
	rooms = lemin->rooms;
	while (rooms && (rooms = rooms->next))
		rooms->pos = ++counter;
	return (0);
}

static int	get_first_room(char *input, t_rooms *rooms)
{
	int		val;
	char	*tmp;

	val = 0;
	if (!(tmp = ft_strchr(input, '-')))
	{
		SETANDPERROR(5, "ERROR. Lost link symbol '-'.");
		return (0);
	}
	tmp = ft_strndup(input, tmp - input);
	while (tmp && rooms)
		if (!ft_strcmp(tmp, rooms->name) && !ft_strdel(&tmp))
			return (rooms->pos);
		else
			rooms = rooms->next;
	if (tmp)
		ft_strdel(&tmp);
	SETANDPERROR(5, "ERROR. Unknown room.");
	return (0);
}

static int	get_second_room(char *input, t_rooms *rooms)
{
	if (errno)
		return (0);
	input = ft_strchr(input, '-') + 1;
	if (!*input)
		SETANDPERROR(5, "ERROR. Lost link room");
	else
	{
		while (rooms)
			if (!ft_strcmp(input, rooms->name))
				return (rooms->pos);
			else
				rooms = rooms->next;
	}
	SETANDPERROR(5, "ERROR. Unknown room.");
	return (0);
}

static int	get_graph_chords(char *input, t_lemin *lemin)
{
	int		y;
	int		x;

	y = get_first_room(input, lemin->rooms);
	x = get_second_room(input, lemin->rooms);
	if (!errno && x == y)
		SETANDPERROR(5, "ERROR. The room cannot refer to itself.");
	if (!errno && ((lemin->map)[y][x] = SETCH))
		(lemin->map)[x][y] = SETCH;
	return (0);
}

int			get_links(char *input, t_lemin *lemin)
{
	links_prepare_to_read(lemin);
	while (input && !errno)
	{
		if (ISCOMMENT(input) || (ISCOMMAND(input) && (!ISSTART(input) &&
			!ISEND(input))))
			ft_strdel(&input);
		else if (ISCOMMAND(input) && (ISSTART(input) || ISEND(input)))
			SETANDPERROR(5, "ERROR. Forbidden commands.");
		else
			get_graph_chords(input, lemin);
		ft_strdel(&input);
		input = lemin_get_line();
	}
	if (input)
		ft_strdel(&input);
	return (0);
}
