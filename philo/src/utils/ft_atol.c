/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:57:19 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/08/18 13:27:49 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *s, int *atol_flag)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*atol_flag = true;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (atol_error_message(atol_flag));
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (atol_error_message(atol_flag));
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}
