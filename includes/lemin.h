/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:52:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/04 14:24:48 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_rooms
{
	char			*name;
	int				pos;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_lemin
{
	int				ants;
	t_rooms			*rooms;
}					t_lemin;

char		*lemin_get_line(void);
t_lemin		*get_t_lemin(void);

#endif
