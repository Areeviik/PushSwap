/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:29:57 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/04 13:30:08 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing1(t_stack *s, char **argv)
{
	int		i;
	int		j;
	char	**arg;
	t_list	*tmp;

	i = 0;
	if (ft_strncmp(argv[1], "\0", 1) == 0)
		error("Error\n");
	while (argv[1][i] == ' ')
		i++;
	if (argv[1][i] == '\0')
		error("Error\n");
	i = 0;
	arg = ft_split(argv[1], ' ');
	while (arg[i] != NULL)
	{
		j = 0;
		while (arg[i][j] != '\0')
			++j;
		++i;
	}
	s->size_a = i;
	i = 0;
	while (i < s->size_a)
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				error("Error\nDuplicate arguments");
			j++;
		}
		i++;
	}
	i = s->size_a - 1;
	s->a = ft_lstnew(ft_atoi(arg[i]), -1);
	i--;
	while (i >= 0)
	{
		tmp = ft_lstnew(ft_atoi(arg[i]), -1);
		ft_lstadd_front(&s->a, tmp);
		i--;
	}
	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	parsing2(t_stack *s, int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*tmp;

	s->size_a = argc - 1;
	i = 1;
	while (i <= s->size_a)
	{
		j = 1;
		while (j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error("Error\nDuplicate arguments");
			j++;
		}
		i++;
	}
	i = s->size_a;
	s->a = ft_lstnew(ft_atoi(argv[i]), -1);
	i--;
	while (i >= 1)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]), -1);
		ft_lstadd_front(&s->a, tmp);
		i--;
	}
}
