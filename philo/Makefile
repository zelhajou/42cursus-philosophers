# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 22:57:41 by zelhajou          #+#    #+#              #
#    Updated: 2024/02/02 15:45:57 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread 
OBJ_DIR = obj/
SRC_DIR = src/
UTILS_DIR = utils/
INCLUDES = -I include/

SRC = $(SRC_DIR)main.c \
      $(UTILS_DIR)libft.c \
      $(UTILS_DIR)parse_args.c \
      $(SRC_DIR)philo_actions.c \
      $(SRC_DIR)philo_states.c \
      $(SRC_DIR)philo_threads.c \
      $(SRC_DIR)simulation_init.c \
      $(SRC_DIR)health_monitor.c \
      $(UTILS_DIR)print_status.c \
	  $(UTILS_DIR)utils.c \
	  $(UTILS_DIR)validate_args.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c include/philosopher.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
