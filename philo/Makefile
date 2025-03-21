# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 17:27:32 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/03/19 14:26:08 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = philo
NAME2 = philo_processes
FLAGS = -pthread
CC = cc
SRCS1 = tutorial.c
SRCS2 = tutorial2.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

all: $(NAME1) # $(NAME2)

$(NAME1): $(OBJS1)
		$(CC) $(FLAGS) -o $(NAME1) $(OBJS1)

$(NAME2): $(OBJS2)
		$(CC) $(FLAGS) -o $(NAME2) $(OBJS2)

clean:
		rm -f $(OBJS1)
# rm -f $(OBJS2)

fclean: clean
		rm -f $(NAME1)
# rm -f $(NAME2)
re: fclean all

val: 
	valgrind ./$(NAME1)

.PHONY: all clean fclean re
