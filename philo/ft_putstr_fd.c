/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:35:56 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/06/02 15:36:41 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	// Arguments: char c – the character to write, int fd – the file descriptor to write to.
	// Returns: Nothing (void function).
	// This function writes the character 'c' to the file descriptor 'fd' using the write system call.
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	// Arguments: char *s – the string to write, int fd – the file descriptor to write to.
	// Returns: Nothing (void function).
	// This function writes the string 's' to the file descriptor 'fd' by writing each character individually using ft_putchar_fd.
	size_t	n;

	n = 0;
	while (s[n])
	{
		ft_putchar_fd(s[n], fd);
		n++;
	}
}