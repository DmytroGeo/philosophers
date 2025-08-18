/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:59:53 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 18:15:44 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*kill_philo(t_data *data, t_philo *philos, int i)
{
	if (log_state(data, philos[i].philo_num, "died"))
		set_stop(data, 1);
	pthread_mutex_unlock(&(philos[i].meal_mutex));
	return (NULL);
}

void	*mon_rout(void *arg)
{
	t_philo	*philos;
	t_data	*data;
	int		i;

	philos = (t_philo *)arg;
	data = philos[0].data;
	while (!get_stop(data))
	{
		i = -1;
		while (++i < data->num_philos && !get_stop(data))
		{
			pthread_mutex_lock(&(philos[i].meal_mutex));
			if (ms_elapsed_since_start(philos[i].last_meal) > data->time_to_die)
				return (kill_philo(data, philos, i));
			if (data->num_must_eat > 0
				&& philos[i].meals_eaten >= data->num_must_eat)
				data->satiated++;
			pthread_mutex_unlock(&(philos[i].meal_mutex));
		}
		if (data->num_must_eat > 0 && data->satiated >= data->num_philos)
			set_stop(data, 1);
		usleep(1000);
	}
	return (NULL);
}
