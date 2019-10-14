/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:55:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/14 12:20:37 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_lemin		*lemin_read_input(void)
{
	t_lemin	*lemin;
	char	*input;

	lemin = get_t_lemin();
	lemin->ants = get_ants(lemin);
	input = get_rooms(lemin);
	if (!errno && !input)
		SETANDPERROR(5, "ERROR. Empty line. read.c:24");
	if (!errno && input)
		get_links(ft_strdup(input), lemin);
	if (input)
		ft_strdel(&input);
	return (lemin);
}

static int	add_line_to_input_buf(t_lemin *lemin, char *input)
{
	char	*tmp;
	char	*tmp_lemin_input;

	if (!lemin || !input || !*input)
		return (0);
	if (!lemin->input)
		lemin->input = ft_strjoin(input, "\n");
	else
	{
		tmp = ft_strjoin(input, "\n");
		tmp_lemin_input = lemin->input;
		lemin->input = ft_strjoin(lemin->input, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp_lemin_input);
	}
	return (0);
}

char		*lemin_get_line(t_lemin *lemin)
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
	if (*line && !add_line_to_input_buf(lemin, line))
		return (line);
	if (line)
		ft_strdel(&line);
	if (tmp)
		ft_strdel(&tmp);
	return (NULL);
}
