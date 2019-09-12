/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:55:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/12 15:33:45 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	check_rooms_errors(t_lemin *lemin)
{
	if (!(lemin->rooms))
		SETANDPERROR(5, "ERROR. No rooms.");
	else if (!lemin->start_room)
		SETANDPERROR(5, "ERROR. No start room.");
	else if (!lemin->end_room)
		SETANDPERROR(5, "ERROR. No end room.");
	return ((!errno ? 0 : 1));
}

t_lemin		*lemin_read_input(void)
{
	t_lemin	*lemin;
	char	*input;

	if (!(lemin = get_t_lemin()))
		return (NULL);
	lemin->ants = get_ants();
	while (!errno && (input = lemin_get_line()) && ft_is_room(input))
	{
		if (ISCOMMENT(input) || (ISCOMMAND(input) && (!ISSTART(input) || !ISEND(input))))
			ft_strdel(&input);
		else
			lemin->rooms = add_room(lemin, input)
		if (input)
			ft_strdel(&input);
	}
//	if (!errno && !input && SETANDPERROR(5, "ERROR. Empty string."))
//		return (lemin);
	if (!errno && check_rooms_errors(lemin))
		return (lemin);
//	else if (!errno && (lemin->links = add_link(lemin->links)))
//		ft_strdel(&input);
//	while (!errno && (input = lemin_get_line()) && ft_is_link(input))
//	{
//		lemin->links = add_link(lemin->links, input);
//		ft_strdel(&input);
//	}
	if (input)
		ft_strdel(&input);
	return (lemin);
}

char		*lemin_get_line(void)
{
	char	*line;
	char	*tmp;
	char	*buf;
	int		ret;

	tmp = NULL;
	buf = ft_strnew(1);
	line = ft_strnew(0);
	while ((ret = read(STDIN_FILENO, buf, 1)) && *buf != '\n')
	{
		tmp = line;
		line = ft_strjoin(line, buf);
		ft_strdel(&tmp);
	}
	if (buf)
		ft_strdel(&buf);
	if (*line)
		return (line);
	if (line)
		ft_strdel(&line);
	if (tmp)
		ft_strdel(&tmp);
	return (NULL);
}
