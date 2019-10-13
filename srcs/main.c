/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:49:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/13 18:43:40 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

//test function
static void	print_map(t_lemin *lemin)
{
	if (lemin)
	{}
//	int		y;
//	int		x;
//	int		side;
//	int		counter;
//	char	**map;
//
//	y = 0;
//	x = 0;
//	counter = 0;
//	side = 0;
//	map = lemin->map;
//	if (map && *map)
//		side = ft_strlen(map[y]);
//	ft_printf("%4c", ' ');
//	while (counter < side)
//		ft_printf("%-5d", (counter++) + 1);
//	ft_printf("\n");
//	while (map[y])
//	{
//		ft_printf("%-4d", y + 1);
//		while (map[y][x])
//			ft_printf("%-5c", map[y][x++]);
//		ft_printf("\n");
//		x = 0;
//		++y;
//	}
//	ft_printf("\n");
}

//int			print_final_ways(t_way **ways)
//{
//	t_way	*way;
//	int		c = 0;
//
//	ft_printf("<<<<print_ways>>>>\n");
//	while (ways && *ways)
//	{
//		way = *ways;
//		ft_printf("%d |", c++);
//		while (way)
//		{
//			ft_printf("%s", way->name);
//			if (way->next)
//				ft_printf("->");
//			else
//				ft_printf("\n");
//			way = way->next;
//		}
//		++ways;
//	}
//	return (0);
//}


int					main(void)
{
	unsigned int	counter = 0;
	t_lemin	*lemin;

	lemin = lemin_read_input();
	if (!errno)
	{
//		ft_printf("start index rooms BFS lvl.\n");
		indexation_lvl(lemin->rooms, lemin->map, lemin->start_room->pos, 1);
		clear_one_lvl_links(lemin);
		clear_parent_links(lemin);
		clear_not_valid_rooms(lemin);
//		ft_printf("start find ways:)\n");
		while (lemin_find_ways(lemin) == 1)
		{
			++counter;
//			ft_printf("counter |%u|\n", counter);
			if (counter == MAX_COUNTER)
				break;
//			print_final_ways(lemin->turn);
		}
	}
	if (!errno && (!lemin->ways || !*(lemin->ways)))
		SETANDPERROR(5, "ERROR. No ways.");
	if (!errno)
	{
		ft_printf("%s\n", lemin->input);
		clear_overlapping(lemin);
		send_ants(lemin);
	}
//	ft_printf("\n|final ways|\n");
//	print_final_ways(lemin->ways);
//	ft_printf("|final ways|\n\n");
//	ft_printf("counter |%u|\n", counter);
	if (lemin && lemin->map)
		print_map(lemin);
	if (lemin)
		clear_t_lemin(lemin);
	return (0);
}
