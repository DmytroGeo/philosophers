/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:08:02 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 17:25:10 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_stop(t_data *data)
{
	int	i;

	pthread_mutex_lock(&(data->state_mutex));
	i = data->stop;
	pthread_mutex_unlock(&(data->state_mutex));
	return (i);
}
