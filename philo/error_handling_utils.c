/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:39:41 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/06/02 15:42:42 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}

int	time_is_a_number(char **av)
{
	if (is_number(av[1]) && is_number(av[2]) && \
		is_number(av[3]) && is_number(av[4]))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	time_is_positive(char **av)
{
	if (ft_atoi(av[1]) > 0 && ft_atoi(av[2]) > 0 && \
		ft_atoi(av[3]) > 0 && ft_atoi(av[4]) > 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
