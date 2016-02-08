# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2015/02/12 15:21:25 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

CC =			clang

FLAGS =			-Wall -Werror -Wextra -O3

HEADER =		push_swap.h

HEADER_DIR =	-I ./includes/ -I $(FT_LIB_DIR)

LIBRARIES =		-L$(FT_LIB_DIR) -l$(FT_LIB_NAME)

FT_LIB_NAME =	ft

FT_LIB =		$(FT_LIB_DIR)lib$(FT_LIB_NAME).a

FT_LIB_DIR =	./libft/

SRC_DIR =		./srcs/

SRC_COMPILED =	main.o \
				array_operations.o \
				compute_answer.o \
				generate_a.o \
				get_original.o \
				isintstring.o \
				print_things.o \
				ps_error.o \
				ps_rotate.o \
				ps_swap.o \
				vamp_count.o \
				putcounter.o \
				check_answer.o \
				deal_options.o

COMPILED =		$(SRC_COMPILED)

all: $(NAME)

$(NAME): $(FT_LIB) $(SRC_COMPILED)
	$(CC) -o $(NAME) $(FLAGS) $(LIBRARIES) $(HEADER_DIR) $(SRC_COMPILED)

$(SRC_COMPILED): %.o: $(SRC_DIR)%.c
	$(CC) -c $(FLAGS) $(HEADER_DIR) $< -o $@

$(FT_LIB):
	@make -C $(FT_LIB_DIR);

clean:
	make clean -C $(FT_LIB_DIR)
	-/bin/rm -f $(COMPILED)

fclean: clean
	make fclean -C $(FT_LIB_DIR)
	-/bin/rm -f $(NAME)

re: fclean all
