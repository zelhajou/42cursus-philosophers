# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 22:57:41 by zelhajou          #+#    #+#              #
#    Updated: 2024/01/18 22:51:11 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = 
OBJ_DIR = obj/
SRC = src/main.c utils/libft.c utils/utils.c
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)
INCLUDES = -I include/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)*/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


