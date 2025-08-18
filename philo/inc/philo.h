/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:32:13 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 19:26:07 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdbool.h>
# include <string.h> // memset,
# include <stdio.h> // printf, 
# include <stdlib.h> // malloc, free, 
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h> //for:
// pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock.

typedef struct s_data
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				num_must_eat;
	long			start_time;
	int				stop;
	int				satiated;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
}	t_data;

typedef struct s_philo
{
	int				philo_num;
	int				left_fork;
	int				right_fork;
	long			last_meal;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;
	t_data			*data;
}	t_philo;

// the reason we have t_data *data in philo is because
// we can only pass one arg to ph_rout

long	ms_elapsed_since_start(long start);
int		parse_args(int ac, char **av, t_data *data);
long	ft_atol(const char *s, int *atol_flag);
long	atol_error_message(int *atol_flag);
void	check_data_err(int flag);
int		init_data(t_data *data);
int		free_all(t_data *data, t_philo *philos);
int		init_mutexes(t_data *data);
int		init_philos(t_data *data, t_philo **philos);
int		run_philos(t_data *data, t_philo *philos);
long	get_ms_time(void);
void	*ph_rout(void *arg);
void	*mon_rout(void *arg);
int		get_stop(t_data *data);
void	wait_loop(long time_to_sleep);
void	eat(t_philo	*philo);
void	set_stop(t_data *data, int i);
int		log_state(t_data *data, int id, const char *msg);

#endif