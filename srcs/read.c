/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:55:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/10 13:06:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_lemin		*lemin_read_input(void)
{
	t_lemin	*lemin;
	char	*input;

	lemin = get_t_lemin();
	lemin->ants = get_ants();
	input = get_rooms(lemin);
	if (!errno && !input)
		SETANDPERROR(5, "ERROR. Empty line. read.c:24");
	if (!errno && input)
		get_links(ft_strdup(input), lemin);
//	ft_printf("errno -> |%ld| input |%s|\n", errno, input);
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
