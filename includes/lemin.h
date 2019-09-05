/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:52:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/05 11:32:40 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

# define ISCOMMAND(str) ((str[0] == '#' && str[1] == '#'))
# define ISCOMMENT(str) ((str[0] == '#' && str[1] != '#'))
# define ISDIGIT(x) ((x >= '0' && x <= '9'))
# define SETERRNO(x) (errno = x)
# define MAXANTS 1 //LLONG_MAX

typedef struct		s_rooms
{
	char			*name;
	int				pos;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_lemin
{
	__int128		ants;
	t_rooms			*rooms;
}					t_lemin;

char				*lemin_get_line(void);
t_lemin				*get_t_lemin(void);
t_lemin				*lemin_read_input(void);
long long int		get_ants(void);

#endif
