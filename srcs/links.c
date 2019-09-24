/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:20:18 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/24 18:27:17 by blukasho         ###   ########.fr       */
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

int			get_links(char *input, t_lemin *lemin)
{
	if (input)
		ft_strdel(&input);//debug
	links_prepare_to_read(lemin);
	return (0);
}
