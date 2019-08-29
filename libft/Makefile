# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 12:56:17 by blukasho          #+#    #+#              #
#*   Updated: 2019/06/23 15:12:46 by blukasho         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	   ft_strrchr.c ft_strcmp.c ft_strstr.c ft_strncmp.c ft_strnstr.c\
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	   ft_putendl_fd.c ft_putnbr_fd.c ft_count_words.c ft_lstnew.c\
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	   ft_strndup.c ft_get_arr.c ft_is_lower.c ft_is_upper.c ft_is_space.c\
	   get_next_line.c ft_strlen_chr.c ft_putstr_arr.c ft_str_del_arr.c\
	   ft_int_arr_mult.c ft_int_arr_subtr.c ft_strchrreplace.c\
	   ft_sum_two_digits.c ft_pos_exp_of_digit.c ft_neg_exp_of_digit.c\
	   ft_int_arr_comparing.c ft_print_int_arr.c ft_strlenarr.c\
	   t_sum_two_digits_del.c check_period.c ft_sum.c ft_get_double_bits.c\
	   ft_get_double_exp.c ft_get_double_man.c\
	   ft_print_double_bits.c ft_len_of_digit.c\

SRCS_FT_PRINTF =  additional_functions.c additional_functions_1.c\
				  additional_functions_double.c check_errors.c\
				  convert_double.c ft_printf.c ft_printf_parser.c\
				  main_function.c parse_flags.c\
				  result_preparation.c print_char.c print_pointer.c\
				  print_unsigned_digits.c print_hexdecimal.c print_double.c\
				  print_digits.c print_octal.c round_double.c\
				  print_percent.c print_string.c\

OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

OBJ_FT_PRINTF = $(addprefix $(OBJ_PATH), $(SRCS_FT_PRINTF:.c=.o))

OBJ_PATH = objs/

SRCS_PATH = srcs/

SRCS_PATH_FT_PRINTF = srcs/ft_printf/

FLAGS = -Wall -Wextra -Werror -I includes

DEBUG_FLAGS = -g3 -fsanitize=address

LIBFT = libft.a

DEBUG_LIBFT = libft.a

all: make_objs_path $(LIBFT)

set_debug_flags: 
	@$(eval FLAGS=$(FLAGS) $(DEBUG_FLAGS))

debug: set_debug_flags all

make_objs_path:
	@mkdir -p $(OBJ_PATH)

$(LIBFT): $(OBJ) $(OBJ_FT_PRINTF)
	ar -rv $(LIBFT) $^
	ranlib $(LIBFT)

$(OBJ_PATH)%.o: $(SRCS_PATH_FT_PRINTF)%.c
	gcc $(FLAGS) -c $< -o $@
 
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	gcc $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re
