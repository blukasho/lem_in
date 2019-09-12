/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:12:18 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/12 14:35:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		ft_is_room(char *input)
{
	if (ISCOMMENT(input) || ISCOMMAND(input))
		return (1);
	if (ft_strchr(input, ' '))
		return (1);
	return (0);
}
