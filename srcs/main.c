/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:49:43 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/14 12:47:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int					print_final_ways(t_way **ways)
{
	t_way	*way;
	int		c;

	c = 0;
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
		if (counter >= MAX_COUNTER && lemin->ways)
			break ;
	}
	if (!errno && (!lemin->ways || !*(lemin->ways)))
		SETANDPERROR(5, "ERROR. No ways.");
	if (!errno)
	{
		if (!(argc && check_flag(argv, "--no-map")))
			ft_printf("%s\n", lemin->input);
		clear_overlapping(lemin);
		send_ants(lemin, !check_flag(argv, "--no-out"), 1);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_lemin			*lemin;

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
