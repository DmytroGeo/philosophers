/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:27:00 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 13:41:42 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_data_err(int flag)
{
	if (flag == 0)
		write(2, "Number of philosophers must be greater than 0\n", 47);
	else if (flag == 1)
		write(2, "Time to die must be at least 0\n", 32);
	else if (flag == 2)
		write(2, "Time to eat must be at least 0\n", 32);
	else if (flag == 3)
		write(2, "Time to sleep must be at least 0\n", 34);
	else if (flag == 4)
	{
		write(2, "Number of times a philosopher ", 31);
		write(2, "must eat must be greater than 0\n", 33);
	}
}

long	atol_error_message(int *atol_flag)
{
	*atol_flag = false;
	write(2, "Argument must be a whole number\n", 33);
	return (0);
}
