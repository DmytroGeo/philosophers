/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:56:19 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 15:02:02 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all(t_data *data, t_philo *philos)
{
	int	i;

	if (philos)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&(philos[i].meal_mutex));
			i++;
		}
		free(philos);
	}
	if (data->forks)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&((data->forks)[i]));
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&(data->print_mutex));
	pthread_mutex_destroy(&(data->state_mutex));
	return (EXIT_SUCCESS);
}
