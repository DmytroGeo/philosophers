/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:45:21 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/19 20:49:14 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_data(t_data *data)
{
	if (data->num_philos < 1)
		return (check_data_err(0), EXIT_FAILURE);
	if (data->time_to_die < 0)
		return (check_data_err(1), EXIT_FAILURE);
	if (data->time_to_eat < 0)
		return (check_data_err(2), EXIT_FAILURE);
	if (data->time_to_sleep < 0)
		return (check_data_err(3), EXIT_FAILURE);
	if (data->num_must_eat == 0)
		return (check_data_err(4), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_args(int ac, char **av, t_data *data)
{
	int	flag;

	if (ac != 5 && ac != 6)
		return (check_data_err(5), EXIT_FAILURE);
	memset(data, 0, sizeof(*data));
	data->num_must_eat = -1;
	data->num_philos = (int)ft_atol(av[1], &flag);
	if (flag == false)
		return (EXIT_FAILURE);
	data->time_to_die = ft_atol(av[2], &flag);
	if (flag == false)
		return (EXIT_FAILURE);
	data->time_to_eat = ft_atol(av[3], &flag);
	if (flag == false)
		return (EXIT_FAILURE);
	data->time_to_sleep = ft_atol(av[4], &flag);
	if (flag == false)
		return (EXIT_FAILURE);
	if (ac == 6)
	{
		data->num_must_eat = (int)ft_atol(av[5], &flag);
		if (flag == false)
			return (EXIT_FAILURE);
	}
	return (check_data(data));
}
