/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:09:22 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/06/02 15:27:19 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// question 1: how can I time things?
long find_time_difference(t_time end, t_time start)
{
	long temp;
	
	temp = ((end.tv_sec - start.tv_sec) % 1000000);
	temp *= 1000000;
	temp += (end.tv_usec - start.tv_usec);
	return(temp);
}

int main(int ac, char **av)
{
	t_time start_of_program;
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_think;

	if (error_handling(ac, av) == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	number_of_philosophers = ft_atoi(av[1]);
	time_to_die = ft_atoi(av[2]);
	time_to_eat = ft_atoi(av[3]);
	time_to_think = ft_atoi(av[4]);
	
	gettimeofday(&start_of_program, NULL);

}





