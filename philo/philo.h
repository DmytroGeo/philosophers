/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:32:13 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/06/02 15:36:20 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <limits.h>
#include <string.h> // memset,
#include <stdio.h> // printf, 
#include <stdlib.h> // malloc, free, 
#include <unistd.h> // write, usleep
#include <sys/time.h> // gettimeofday
#include <pthread.h> //for:
// pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

typedef struct s_fork
{
	int *state; // in use or not in use
} t_fork;

typedef struct s_philosopher
{
	int number;
	int is_alive;
	int *state; // eating, sleeping, thinking
	int *time_to_die;
	int *time_to_eat;
	int *time_to_sleep;
} t_philosopher;

typedef struct s_table
{
	// a list of philosophers
	// a list of forks
} t_table;

typedef struct timeval t_time;

long find_time_difference(t_time end_of_program, t_time start_of_program);
int ft_isdigit(char c);
int is_number(char *str);
int ft_atoi(const char *str);
int error_handling(int ac, char **av);
int time_is_a_number(char **av);
int time_is_positive(char **av);
void	ft_putstr_fd(char *s, int fd)
#endif