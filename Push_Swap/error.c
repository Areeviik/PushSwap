/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:47:57 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/13 16:48:08 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned long	ft_strlen(const char *str)
{
	unsigned int	l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	return (l);
}

static void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen((char *)s));
}

static void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

int	error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(1);
}
