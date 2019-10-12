/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:52:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/10/12 15:03:41 by blukasho         ###   ########.fr       */
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
# define ISLINK(x) ((!ft_strchr(x, ' ') && ft_strchr(x, '-')))
# define ISDIGIT(x) ((x >= '0' && x <= '9'))
# define ISSTART(str) (!ft_strcmp(str, "##start"))
# define ISEND(str) (!ft_strcmp(str, "##end"))
# define SETERRNO(x) (errno = x)
# define MAXANTS INT_MAX //LLONG_MAX
# define FILLCH '0'
# define SETCH '1'

# define DEFAULTROOM 0
# define STARTROOM 1
# define ENDROOM 2

#define MAX_COUNTER 15000

typedef struct		s_rooms
{
	char			*name;
	int				pos; //position in graph map
	int				type;
	int				coord_x;
	int				coord_y;
	int				index;
	int				sw;
	int				input_links;
	int				output_links;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_way
{
	int				pos;
	struct s_way	*next;
}					t_way;

typedef struct		s_lemin
{
	__int128		ants;
	t_rooms			*rooms;
	t_rooms			*start_room;
	t_rooms			*end_room;
	t_way			**ways;//all ways START->END
	t_way			**turn;
	char			**map; //rooms len * len
	//карта комнат +
	//комната не может ссылаться сама на себя + 
	//невозможные комнаты +
	//пустые комнаты невозможны
	//мусор
	//##start ##end невозможен
	//старт без ссылки невозможен и конец
}					t_lemin;

char				*lemin_get_line(void);
t_lemin				*get_t_lemin(void);
t_rooms				*get_t_rooms(char *name);
char				*get_rooms(t_lemin *lemin);
t_lemin				*lemin_read_input(void);
long long int		get_ants(void);
int					clear_t_lemin(t_lemin *lemin);
int					clear_t_rooms(t_rooms *rooms);
char				*valid_room_name(char *name);
void				valid_room_coords(t_rooms *room, char *coords);
t_rooms				*add_start_end_rooms(t_lemin *lemin, t_rooms *rooms, char *in, int tp);
int					get_links(char *input, t_lemin *lemin);
int					get_len_rooms(t_rooms *rooms);
int					lemin_find_ways(t_lemin *lemin);
t_way				*get_t_way(int pos);
t_way				**add_way_to_ways(t_way **ways, t_way *way);
int					clear_ways(t_way **ways);
int					clear_way(t_way *way);
t_way				*add_room_to_way(t_way *ways, int room);
t_way				*cp_way_add_room(t_way *way, int room);
int					check_duplicates(t_way *way);
int					check_final_way(t_rooms *end, t_way *way);
int					print_final_ways(t_way **ways);
int					init_start_ways(t_lemin *lemin, int start);
int					sort_ways(t_way **ways, char **map);
int					indexation_lvl(t_rooms *rooms, char **map, int start, int index);
int					check_lvl(t_rooms *rooms, int pos_a, int pos_b);
int					clear_one_lvl_links(t_lemin *lemin);
int					clear_parent_links(t_lemin *lemin);
int					clear_not_valid_rooms(t_lemin *lemin);
t_rooms				*get_room(t_rooms *rooms, int pos);

#endif


