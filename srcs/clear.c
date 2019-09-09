/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:51:42 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/09 13:14:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		clear_t_lemin(t_lemin *lemin)
{
	if (!lemin)
		return (0);
	if (lemin->rooms)
		clear_t_rooms(lemin->rooms);
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
		if ((rooms->type) == STARTROOM)
			ft_printf("STARTROOM delete.\n");
		else if ((rooms->type) == ENDROOM)
			ft_printf("ENDROOM delete.\n");
		else if ((rooms->type) == DEFAULTROOM)
			ft_printf("DEFAULTROOM delete.\n");
		else
			ft_printf("UKNOWNROOM delete.\n");
		if (rooms->name)
		{
			ft_printf("room name |%s| delete.\n", rooms->name);
			ft_strdel(&(rooms->name));
		}
		tmp = rooms;
		rooms = rooms->next;
		free(tmp);
	}
	return (0);
}
