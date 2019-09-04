/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:22:27 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/04 14:24:48 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_lemin		*get_t_lemin(void)
{
	t_lemin	*lemin;

	lemin = (t_lemin *)malloc(sizeof(t_lemin));
//	ft_bzero(lemin, sizeof(t_lemin));
	return (lemin);
}
