/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:55:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/04 14:24:57 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

//t_lemin		*ft_readmap(void)
//{
//
//}

char		*lemin_get_line(void) {
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
