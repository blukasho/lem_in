/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:49:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/13 23:19:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

//test function
static void	print_map(t_lemin *lemin)
{
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

int			print_final_ways(t_way **ways)
{
	t_way	*way;
	int		c = 0;

	ft_printf("\n");
	while (ways && *ways)
	{
		way = *ways;
		ft_printf(">%d< |", c++);
		while (way)
		{
			ft_printf("%s", way->name);
			if (way->next)
				ft_printf("->");
			else
				ft_printf("\n");
			way = way->next;
		}
		++ways;
	}
	return (0);
}

static int			run_lemin(t_lemin *lemin, int argc, char **argv)
{
	unsigned int	counter;

	counter = 0;
	indexation_lvl(lemin->rooms, lemin->map, lemin->start_room->pos, 1);
	clear_one_lvl_links(lemin);
	clear_parent_links(lemin);
	clear_not_valid_rooms(lemin);
	while (lemin_find_ways(lemin) == 1)
	{
		++counter;
		if (counter == MAX_COUNTER)
			break;
	}
	if (!errno && (!lemin->ways || !*(lemin->ways)))
		SETANDPERROR(5, "ERROR. No ways.");
	if (!errno)
	{
		if (!(argc && check_flag(argv, "--no-map")))
			ft_printf("%s\n", lemin->input);
		clear_overlapping(lemin);
		send_ants(lemin, !check_flag(argv, "--no-out"));
	}
	if (lemin && lemin->map)
		print_map(lemin);
	return (0);
}


int					main(int argc, char **argv)
{
	t_lemin	*lemin;

	--argc;
	++argv;
	if (argc && check_flag(argv, "--help") &&
		ft_printf(CONFIG, NO_OUT, PRINT_WAYS, NO_MAP, HELP))
		return (0);
	lemin = lemin_read_input();
	if (!errno)
		run_lemin(lemin, argc, argv);
	if (!errno && argc && check_flag(argv, "--print-ways"))
		print_final_ways(lemin->ways);
	if (lemin)
		clear_t_lemin(lemin);
	return (0);
}
