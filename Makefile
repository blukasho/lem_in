#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/08/29 10:35:46 by blukasho          #+#    #+#             *#
#*   Updated: 2019/09/09 10:57:32 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS=main.c read.c init.c ants.c rooms.c clear.c

OBJ=$(addprefix $(OBJDIR), $(SRCS:.c=.o))

OBJDIR=./objs/

SRCDIR=srcs/

NAME=lem-in

FLAGS=-Wall -Wextra -Werror

DEBUG=-g3 -fsanitize=address

INCLUDE=-I./includes/

LIBNAME=libft.a

LIBPATH=./libft/

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBPATH)$(LIBNAME) $(OBJ)
	gcc $(FLAGS) $(LIBPATH)$(LIBNAME) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) $(INCLUDE) -c $< -o $@
	ar -rv $(LIBPATH)$(LIBNAME) $@
	ranlib $(LIBPATH)$(LIBNAME)

$(LIBPATH)$(LIBNAME):
	make -C $(LIBPATH)

debug: debugflags debuglib all

debugflags:
	$(eval FLAGS=$(FLAGS) $(DEBUG))

debuglib:
	make debug -C $(LIBPATH)

makelib:
	make -C $(LIBPATH)

clean:
	make clean -C $(LIBPATH)
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -rvf $(NAME)

re: fclean all

.PHONY: all clean fclean re
