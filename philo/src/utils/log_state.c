/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:16:35 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 17:25:42 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	log_state(t_data *data, int id, const char *msg)
{
	long	time_stamp;

	pthread_mutex_lock(&(data->state_mutex));
	if (data->stop)
	{
		pthread_mutex_unlock(&(data->state_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(data->state_mutex));
	time_stamp = ms_elapsed_since_start(data->start_time);
	pthread_mutex_lock(&(data->print_mutex));
	printf("%ld %d %s\n", time_stamp, id, msg);
	pthread_mutex_unlock(&(data->print_mutex));
	return (1);
}
