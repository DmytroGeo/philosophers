/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:43:42 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 13:52:16 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data)
{
	data->stop = false;
	data->satiated = false;
	data->forks = NULL;
	if (pthread_mutex_init(&(data->print_mutex), NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(data->state_mutex), NULL) != 0)
		return (pthread_mutex_destroy(&(data->print_mutex)), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
