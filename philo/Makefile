# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 17:27:32 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/06/02 15:36:58 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -pthread
CC = cc
SRCS = main.c \
		error_handling_utils.c \
		ft_atoi.c \
		error_handling.c \
		ft_pustr_fd.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

val: 
	valgrind ./$(NAME1)

.PHONY: all clean fclean re
