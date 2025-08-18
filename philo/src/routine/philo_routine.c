/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:00:08 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 19:09:14 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_rout(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->philo_num % 2 == 0)
		usleep(1000);
	while (!get_stop(ph->data))
	{
		eat(ph);
		if (ph->data->num_must_eat > 0
			&& ph->meals_eaten >= ph->data->num_must_eat)
			break ;
		if (!log_state(ph->data, ph->philo_num, "is sleeping"))
			break ;
		wait_loop(ph->data->time_to_sleep);
		if (!log_state(ph->data, ph->philo_num, "is thinking"))
			break ;
	}
	return (NULL);
}
