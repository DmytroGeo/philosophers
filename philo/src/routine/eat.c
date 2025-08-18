/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:16:54 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 19:11:13 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo	*philo)
{
	t_data *data;

	data = philo->data;
	pthread_mutex_lock(&((data->forks)[philo->left_fork]));
	if (!log_state(data, philo->philo_num, "has taken a fork"))
		return ;
	pthread_mutex_lock(&((data->forks)[philo->right_fork]));
	if (!log_state(data, philo->philo_num, "has taken a fork"))
		return ;
	pthread_mutex_lock(&(philo->meal_mutex));
	philo->last_meal = get_ms_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&(philo->meal_mutex));
	if (!log_state(data, philo->philo_num, "is eating"))
		return ;
	wait_loop(data->time_to_eat);
	pthread_mutex_unlock(&((data->forks)[philo->left_fork]));
	pthread_mutex_unlock(&((data->forks)[philo->right_fork]));
}
