/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:49:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/23 16:13:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

//test function
static void	print_map(t_lemin *lemin)
{
	int		y;
	int		x;
	int		side;
	int		counter;
	char	**map;

	y = 0;
	x = 0;
	counter = 0;
	side = 0;
	map = lemin->map;
	if (map && *map)
		side = ft_strlen(map[y]);
	ft_printf("%4c", ' ');
	while (counter < side)
		ft_printf("%-5d", counter++);
	ft_printf("\n");
	while (map[y])
	{
		ft_printf("%-4d", y);
		while (map[y][x])
			ft_printf("%-5c", map[y][x++]);
		ft_printf("\n");
		x = 0;
		++y;
	}
	ft_printf("\n");
}

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
			ft_printf("room name -> |%s| pos |%d| type ->|", rooms->name, rooms->pos);
			if (rooms->type == STARTROOM)
				ft_printf("START ROOM|\n");
			else if (rooms->type == ENDROOM)
				ft_printf("END ROOM|\n");
			else if (rooms->type == DEFAULTROOM)
				ft_printf("DEFAULT ROOM|\n");
			else
				ft_printf("NONAME ROOM|\n");
			rooms = rooms->next;
		}
		ft_printf("|END PRINT ROOMS|\n\n");
	}
	if (lemin && lemin->map)
		print_map(lemin);
	if (lemin)
		clear_t_lemin(lemin);
	return (0);
}
