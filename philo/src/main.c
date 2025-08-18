/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:41:51 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 15:06:06 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	if (parse_args(ac, av, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_data(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_mutexes(&data) == EXIT_FAILURE)
		return (free_all(&data, NULL), EXIT_FAILURE);
	if (init_philos(&data, &philos) == EXIT_FAILURE)
		return (free_all(&data, NULL), EXIT_FAILURE);
	if (run_philos(&data, philos) == EXIT_FAILURE)
		return (free_all(&data, philos), EXIT_FAILURE);
	free_all(&data, philos);
	return (EXIT_SUCCESS);
}
