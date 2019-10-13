/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:03:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/13 10:27:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int			check_get_ants_errors(char *input)
{
	if (!errno && ISCOMMAND(input) && (ISSTART(input) || ISEND(input))
		&& SETERRNO(5))
		perror("ERROR. No ants.");
	else if (!errno && !ISDIGIT(*input) && SETERRNO(5))
		perror("ERROR. Wrong input.");
	while (!errno && ISDIGIT(*input))
		++input;
	if (!errno && (*input) && SETERRNO(5))
		perror("ERROR. Wrong input.");
	return (errno);
}

long long int		get_ants(t_lemin *lemin)
{
	long long int	ants;
	char			*input;

	ants = 0;
	while (!errno && (input = lemin_get_line(lemin)))
	{
		if (ISCOMMENT(input) || (ISCOMMAND(input) && !ISSTART(input)))
			ft_strdel(&input);
		if (input && check_get_ants_errors(input) && !ft_strdel(&input))
			return (0);
		if (input && ((ants = ft_atoi(input)) < 1) && !ft_strdel(&input))
		{
			SETERRNO(5);
			perror("ERROR. Wrong number of ants.");
			return (0);
		}
		else if (input && !ft_strdel(&input) && ants <= MAXANTS)
			return (ants);
		else if (ants > MAXANTS && SETERRNO(5))
			perror("ERROR. MAXANTS overflow.");
	}
	if (!errno && !input && SETERRNO(5))
		perror("ERROR. Empty string.");
	return (0);
}
