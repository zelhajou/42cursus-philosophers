# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 22:57:41 by zelhajou          #+#    #+#              #
#    Updated: 2024/01/29 17:47:03 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
OBJ_DIR = obj/
SRC = src/main.c utils/libft.c utils/parse_arguments.c \
      src/philo_actions.c src/philo_states.c src/philo_threads.c \
      src/simulation_init.c src/health_monitor.c utils/print_status.c
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


