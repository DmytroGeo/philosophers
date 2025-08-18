/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:39:03 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 19:22:29 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_loop(long time_to_)
{
	long	start;

	start = get_ms_time();
	while (ms_elapsed_since_start(start) < time_to_)
		usleep(100);
}
