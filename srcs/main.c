/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:49:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/09 13:34:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			main(void)
{
	t_lemin	*lemin;
	t_rooms	*rooms;

	lemin = lemin_read_input();
	if (lemin && (lemin->rooms))
	{
		rooms = lemin->rooms;
		ft_printf("\n|START PRINT ROOMS|\n");
		while (rooms)
		{
			ft_printf("room name -> |%s|\n", rooms->name);
			rooms = rooms->next;
		}
		ft_printf("|END PRINT ROOMS|\n\n");
	}
	if (lemin)
		clear_t_lemin(lemin);
	return (0);
}
