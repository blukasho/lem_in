/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:51:42 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/09 10:58:01 by blukasho         ###   ########.fr       */
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
	tmp = rooms;
	while (rooms)
	{
		if (rooms->name)
			ft_strdel(&(rooms->name));
		rooms = rooms->next;
	}
	free(tmp);
	return (0);
}
