/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:58:01 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/06/02 14:58:19 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

long	ft_intconvert(const char *nptr)
{
	long	i;
	size_t	k;

	i = 0;
	k = 0;
	while (ft_isdigit(nptr[k]))
	{
		i = (10 * i) + (nptr[k] - 48);
		k++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			n;
	const char	*nptr;

	nptr = str;
	n = 0;
	while (ft_isspace(nptr[n]))
		n++;
	if (nptr[n] == '-')
	{
		if ((-1 * ft_intconvert(nptr + n + 1)) < INT_MIN)
			return (0);
		return (-1 * ft_intconvert(nptr + n + 1));
	}
	else if (nptr[n] == '+')
		n++;
	if (ft_isdigit(nptr[n]))
	{
		if ((ft_intconvert(nptr + n)) > INT_MAX)
			return (0);
		return (ft_intconvert(nptr + n));
	}
	return (0);
}