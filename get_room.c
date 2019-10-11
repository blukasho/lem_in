/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:12:20 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/12 02:13:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_rooms	*get_room(t_rooms *rooms, int pos)
{
	while (rooms)
	{
		if (rooms->pos == pos)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}
