/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:40:33 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/16 16:40:47 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *s)
{
	int i;
	t_list	*tmp;

	i = 0;
	tmp = s->a;
	while (i < s->size_a - 1)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		++i;
		tmp = tmp->next;
	}
	return (1);
}

void    alg_2(t_stack *s)
{
	if (s->a->data > s->a->next->data)
	{
		swap(s->a);
		write(1, "sa\n", 3);
	}
}

void    alg_3(t_stack *s)
{
	if(s->a->data > s->a->next->data && s->a->next->data > s->a->next->next->data)  // 3 2 1
	{
		rotate(&s->a);
		write(1, "ra\n", 3);
		swap(s->a);
		write(1, "sa\n", 3);
	}
	else if (s->a->data > s->a->next->data && s->a->data < s->a->next->next->data)  //2 1 3
	{
		swap(s->a);
		write(1, "sa\n", 3);
	}
	else if (s->a->data < s->a->next->data && s->a->data > s->a->next->next->data)  //231
	{
		rrotate(&s->a);
		write(1, "rra\n", 4);
	}
	else if (s->a->data > s->a->next->data && s->a->data > s->a->next->next->data) //312
	{
		rotate(&s->a);
		write(1, "ra\n", 3);
	}
	if (s->a->next->data > s->a->data && s->a->next->data > s->a->next->next->data) // 132
	{
		rrotate(&s->a);
		write(1, "rra\n", 4);
		swap(s->a);
		write(1, "sa\n", 3);
	}
}

void	alg_4(t_stack *s)
{
	int 	min;
	int 	i;
	t_list	*current;

	current = s->a;
	min = find_min(s->a);
	i = 0;
	while (min != current->data)
	{
		++i;
		current = current->next;
	}
	if (i > s->size_a / 2)
	{
		while (i > s->size_a / 2)
		{
			rrotate(&s->a);
			write(1, "rra\n", 4);
			--i;
		}
	}
	else if (i <= s->size_a / 2)
	{
		while (i > 0)
		{
			rotate(&s->a);
			write(1, "ra\n", 3);
			--i;
		}
	}
	pb(s);
	write(1, "pb\n", 3);

/////////////

	// int m = 0;
	// t_list *tmp = s->a;
	// while(m < s->size_a)
	// {
	// 	printf("%d -> %d\n", tmp->data, tmp->index);
    // 	tmp = tmp->next;
	//     m++;
	// }

/////////////Karen

	alg_3(s);
	pa(s);
	write(1, "pa\n", 3);
}

void	alg_5(t_stack *s)
{
	int 	min;
	int		i;
	t_list	*cur;

	cur = s->a;
	min = find_min(cur);
	i = 0;
	while (min != cur->data)
	{
		++i;
		cur = cur->next;
	}
	if (i > s->size_a + 1 / 2)
	{
		while ( i > s->size_a / 2)
		{
			rrotate(&s->a);
			write(1, "rra\n", 4);
			--i;
		}
	}
	else if (i <= s->size_a + 1 / 2)
	{
		while (i > 0)
		{
			rotate(&s->a);
			write(1, "ra\n",3);
			--i;
		}
	}
	pb(s);
	write(1, "pb\n", 3);
	alg_4(s);
	pa(s);
	write(1, "pa\n", 3);
}

