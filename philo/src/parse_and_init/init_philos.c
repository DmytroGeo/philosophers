/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:34:40 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 14:57:33 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data, t_philo **addr_of_philos)
{
	int		i;
	t_philo	*ph_arr;

	ph_arr = malloc(data->num_philos * sizeof(t_philo));
	if (!ph_arr)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->num_philos)
	{
		ph_arr[i].philo_num = i + 1;
		ph_arr[i].right_fork = i;
		ph_arr[i].left_fork = (i + 1) % (data->num_philos);
		ph_arr[i].meals_eaten = 0;
		ph_arr[i].data = data;
		ph_arr[i].last_meal = 0;
		if (pthread_mutex_init(&(ph_arr[i].meal_mutex), NULL) != 0)
			return (free(ph_arr), EXIT_FAILURE);
		i++;
	}
	*addr_of_philos = ph_arr;
	return (EXIT_SUCCESS);
}
