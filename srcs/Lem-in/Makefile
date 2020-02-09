# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 20:12:39 by pdonnie           #+#    #+#              #
#    Updated: 2019/12/15 07:52:24 by pdonnie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB_DIR = ./libft
PRINTF_DIR = ./libft/printf

LIBFT = $(LIBDIR)/libft.a

SOURCE = main.c validator.h validator.c get_next_line.c \
	validator_links.c validator_rooms.c algo_array_of_rooms.c bfs.c \
	algo_prepare.c algo_search_path.c algo_move_ants.c free.c print.c create_and_fill_data.c comments.c \
	algo_del_child.c algo_input_fork.c algo_calc_input_output.c algo_check_from_end_sort_childs_of_end.c \
	validator_get_coordinates.c free_add.c\
	

OBJECTS = main.o validator.o get_next_line.o \
	validator_links.o validator_rooms.o algo_array_of_rooms.o bfs.o \
	algo_prepare.o algo_search_path.o algo_move_ants.o free.o print.o create_and_fill_data.o comments.o \
	algo_del_child.o algo_input_fork.o algo_calc_input_output.o algo_check_from_end_sort_childs_of_end.o \
	validator_get_coordinates.o free_add.o

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECTS)
		gcc -Wall -Wextra -Werror -Werror $(OBJECTS) libft/libft.a libft/printf/libftprintf.a -o $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)
	make -C $(PRINTF_DIR)

%.o: %.c validator.h
		gcc -Wall -Wextra -Werror -Iincludes -c $< -o $@

clean :
		make clean -C $(LIB_DIR)
		make clean -C $(PRINTF_DIR)
		/bin/rm -f $(OBJECTS)

fclean : clean
		make fclean -C $(LIB_DIR)
		make fclean -C $(PRINTF_DIR)
		/bin/rm -f $(NAME)

re : fclean all
