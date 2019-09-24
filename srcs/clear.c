/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:51:42 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/24 12:27:36 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		clear_t_lemin(t_lemin *lemin)
{
	if (!lemin)
		return (0);
	if (lemin->rooms)
		clear_t_rooms(lemin->rooms);
	if (lemin->map)
		ft_str_del_arr(lemin->map);
	free(lemin);
	return (0);
}

int			clear_t_rooms(t_rooms *rooms)
{
	t_rooms	*tmp;

	if (!rooms)
		return (0);
	while (rooms)
	{
		ft_printf("room name -> |%s| type ->|", rooms->name);
		if (rooms->type == STARTROOM)
			ft_printf("START ROOM|\n");
		else if (rooms->type == ENDROOM)
			ft_printf("END ROOM|\n");
		else if (rooms->type == DEFAULTROOM)
			ft_printf("DEFAULT ROOM|\n");
		else
			ft_printf("NONAME ROOM|\n");
		if (rooms->name)
		{
			ft_printf("|%s| delete.\n", rooms->name);
			ft_strdel(&(rooms->name));
		}
		tmp = rooms;
		rooms = rooms->next;
		free(tmp);
	}
	return (0);
}
