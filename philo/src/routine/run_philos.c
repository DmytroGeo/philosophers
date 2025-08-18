/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:04:50 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 15:59:08 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_philos(t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	monitor;

	data->start_time = get_ms_time();
	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		philos[i].last_meal = data->start_time;
		pthread_mutex_unlock(&philos[i].meal_mutex);
	}
	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, ph_rout, &philos[i]) != 0)
			return (EXIT_FAILURE);
	}
	if (pthread_create(&monitor, NULL, mon_rout, &philos[i]) != 0)
		return (EXIT_FAILURE);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(philos[i].thread, NULL);
	return (EXIT_SUCCESS);
}
