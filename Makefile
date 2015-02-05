# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2015/02/05 14:57:52 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

CC =			gcc

FLAGS =			-Wall -Werror -Wextra -O3

HEADER =		push_swap.h

HEADER_DIR =	-I ./includes/ -I $(FT_LIB_DIR)

LIBRARIES =		-L$(FT_LIB_DIR) -l$(FT_LIB_NAME)

FT_LIB_NAME =	ft

FT_LIB =		$(FT_LIB_DIR)lib$(FT_LIB_NAME).a

FT_LIB_DIR =	./libft/

SRC_DIR =		./srcs/

SRC_COMPILED =	main.o \
				ps_error.o \
				isintstring.o

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
