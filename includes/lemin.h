/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:52:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/09/09 16:48:02 by blukasho         ###   ########.fr       */
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

# define SETANDPERROR(error, str) ((SETERRNO(error), perror(str)))
# define ISCOMMAND(str) ((str[0] == '#' && str[1] == '#'))
# define ISCOMMENT(str) ((str[0] == '#' && str[1] != '#'))
# define ISDIGIT(x) ((x >= '0' && x <= '9'))
# define ISSTART(str) (!ft_strcmp(str, "##start"))
# define ISEND(str) (!ft_strcmp(str, "##end"))
# define SETERRNO(x) (errno = x)
# define MAXANTS 1 //LLONG_MAX

# define DEFAULTROOM 0
# define STARTROOM 1
# define ENDROOM 2

typedef struct		s_rooms
{
	char			*name;
	int				pos;
	int				type;
	int				coord_x;
	int				coord_y;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_lemin
{
	int				start;
	int				end;
	__int128		ants;
	t_rooms			*rooms;
}					t_lemin;

char				*lemin_get_line(void);
t_lemin				*get_t_lemin(void);
t_rooms				*get_t_rooms(char *name);
t_rooms				*get_rooms(void);
t_lemin				*lemin_read_input(void);
long long int		get_ants(void);
int					clear_t_lemin(t_lemin *lemin);
int					clear_t_rooms(t_rooms *rooms);

#endif
