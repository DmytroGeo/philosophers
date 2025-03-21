/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:09:22 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/19 17:24:58 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;

void	*funct1(void *ptr)
{
	pthread_mutex_lock(&mutex);
	*(int *)ptr += 5;
	pthread_mutex_unlock(&mutex);
}

void	*roll_dice(void *res)
{
	int value = (rand() % 6) + 1;
	printf("result = %d \n", value);
	*(int *)res = value;	
	return (res);
}

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*print_prime(void *ptr)
{
	pthread_mutex_lock(&mutex);
	printf("%d\n", primes[*(int *)ptr]);
	pthread_mutex_unlock(&mutex);
}

int main(int ac, char **av)
{
	if (ac < 1)
		return (EXIT_FAILURE);
	int i = 0;
	pthread_t *thread;
	int n = 10;
	thread = malloc(n * sizeof(pthread_t));
	pthread_mutex_init(&mutex, NULL);
	while (i < n)
	{
		pthread_create(&thread[i], NULL, print_prime, (void *) &i);
		printf("%d has started\n", i);
		// pthread_join(thread[i], NULL);
		// printf("%d has finished\n", i);		
		i++;	
	}
	i = 0;
	while (i < n)
	{
		pthread_join(thread[i], NULL);
		// pthread_create(&thread[i], NULL, funct1, &x);
		// printf("%d has started\n", i);
		printf("%d has finished\n", i);	
		i++;	
	}	
	// printf("The value of x is %d \n", *res);
	pthread_mutex_destroy(&mutex);
	free(thread);
	return (0);
}

// int main(int ac, char **av)
// {
// 	if (ac < 2)
// 		return (EXIT_FAILURE);
// 	int i = 0;
// 	pthread_t *thread;
// 	int n = atoi(av[1]);
// 	thread = malloc(n * sizeof(pthread_t));
// 	int *res = malloc(n * sizeof(int));
// 	pthread_mutex_init(&mutex, NULL);
// 	while (i < n)
// 	{
// 		pthread_create(&thread[i], NULL, roll_dice, (void *) &res[i]);
// 		printf("%d has started\n", i);
// 		// pthread_join(thread[i], NULL);
// 		// printf("%d has finished\n", i);		
// 		i++;	
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		// pthread_create(&thread[i], NULL, funct1, &x);
// 		// printf("%d has started\n", i);
// 		pthread_join(thread[i], (void **) &res[i]);
// 		printf("%d has finished\n", i);	
// 		i++;	
// 	}	
// 	// printf("The value of x is %d \n", *res);
// 	pthread_mutex_destroy(&mutex);
// 	free(thread);
// 	free(res);
// 	return (0);
// }

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	srand(time(NULL));
// 	pthread_t *thread;
// 	int n = atoi(av[1]);
// 	thread = malloc(n * sizeof(pthread_t));
// 	int *ptr;
// 	pthread_mutex_init(&mutex, NULL);
// 	while (i < n)
// 	{
// 		pthread_create(&thread[i], NULL, roll_dice, NULL);
// 		// printf("%d has started\n", i);
// 		// pthread_join(thread[i], NULL);
// 		// printf("%d has finished\n", i);		
// 		i++;	
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		// pthread_create(&thread[i], NULL, funct1, &x);
// 		// printf("%d has started\n", i);
// 		pthread_join(thread[i], (void **) &ptr);
// 		// printf("%d has finished\n", i);	
// 		i++;	
// 	}	
// 	printf("The value of k is %d \n", *ptr);
// 	pthread_mutex_destroy(&mutex);
// 	return (0);
// }


// int main(void)
// {
// 	int *res;
// 	srand(time(NULL));
// 	pthread_t thread;
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_create(&thread, NULL, roll_dice, NULL);	
// 	pthread_join(thread, (void **) &res);
// 	printf("The value of k is %d \n", *res);
// 	pthread_mutex_destroy(&mutex);
// 	free(res);
// 	return (0);	
// }