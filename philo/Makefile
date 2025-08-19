# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 17:27:32 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/08/19 21:14:47 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror -pthread -g
CC = cc

INCLUDES = -I./inc

OBJ_FOLDER = ./obj
SRC_FOLDER = ./src

SRCS = $(SRC_FOLDER)/main.c \
		$(SRC_FOLDER)/parse_and_init/parse_args.c \
		$(SRC_FOLDER)/parse_and_init/init_data.c \
		$(SRC_FOLDER)/parse_and_init/init_mutexes.c \
		$(SRC_FOLDER)/parse_and_init/init_philos.c \
		$(SRC_FOLDER)/utils/ft_atol.c \
		$(SRC_FOLDER)/utils/err_msg.c \
		$(SRC_FOLDER)/utils/free_all.c \
		$(SRC_FOLDER)/utils/get_ms_time.c \
		$(SRC_FOLDER)/utils/log_state.c \
		$(SRC_FOLDER)/utils/get_stop.c \
		$(SRC_FOLDER)/utils/wait_loop.c \
		$(SRC_FOLDER)/utils/ms_elapsed_since_start.c \
		$(SRC_FOLDER)/utils/set_stop.c \
		$(SRC_FOLDER)/routine/run_philos.c \
		$(SRC_FOLDER)/routine/philo_routine.c \
		$(SRC_FOLDER)/routine/eat.c \
		$(SRC_FOLDER)/routine/monitor_routine.c

OBJS = $(patsubst $(SRC_FOLDER)/%.c, $(OBJ_FOLDER)/%.o, $(SRCS))

all: $(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER):
	@mkdir -p $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
