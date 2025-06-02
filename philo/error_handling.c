/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:32 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/06/02 15:40:39 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error_handling(int ac, char **av)
{
	if (ac < 5 || ac >= 7)
	{
		ft_putstr_fd("Error: Enter 4 or 5 numerical arguments.\n", 2);
		return(EXIT_FAILURE);
	}
	if (time_is_a_number(av) == EXIT_FAILURE)
	{
		ft_putstr_fd("Time must be a number\n", 2);
		return(EXIT_FAILURE);		
	}
	if (time_is_positive(av) == EXIT_FAILURE)		
	{
		ft_putstr_fd("Time must be a positive quantity\n", 2);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}