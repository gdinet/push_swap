# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdinet <gdinet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 03:30:06 by gdinet            #+#    #+#              #
#    Updated: 2021/07/12 14:19:16 by gdinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAG		= -Wall -Wextra -Werror $(INC)

INC			= -I./inc

FT			= libft

SRC			= src/clear.c \
			  src/chunk_sort.c \
			  src/print_game.c \
			  src/insert_sort.c \
			  src/main_push_swap.c \
			  src/parsing.c \
			  src/push.c \
			  src/quick_sort.c \
			  src/rev_rotate.c \
			  src/rotate.c \
			  src/swap.c \
			  src/value_pos.c

SRC2		= src/clear.c \
			  src/main_checker.c \
			  src/print_game.c \
			  src/parsing.c \
			  src/push.c \
			  src/rev_rotate.c \
			  src/rotate.c \
			  src/swap.c

OBJ			= $(SRC:%.c=%.o)

OBJ2		= $(SRC2:%.c=%.o)

NAME		= push_swap

NAME2		= checker

all: 		$(NAME) $(NAME2)

libft:
			make -C $(FT)

$(NAME) :	$(OBJ)
			make -C $(FT)
			$(CC) $(CFLAG) -o $@ $(OBJ) -L./$(FT) -lft

$(NAME2) :	$(OBJ2)
			make -C $(FT)
			$(CC) $(CFLAG) -o $@ $(OBJ2) -L./$(FT) -lft

.c.o:
			$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

clean:
			make -C $(FT) $@
			rm -f $(OBJ) $(OBJ2)

fclean:		clean
			make -C $(FT) $@
			rm -f $(NAME) $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re
