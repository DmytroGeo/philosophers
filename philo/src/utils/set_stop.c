/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:09:16 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 18:11:04 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_stop(t_data *data, int i)
{
	pthread_mutex_lock(&(data->state_mutex));
	data->stop = i;
	pthread_mutex_unlock(&(data->state_mutex));
}
