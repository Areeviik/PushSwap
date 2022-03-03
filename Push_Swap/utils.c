/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:30:16 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/04 13:30:24 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	long	num;

	i = 0;
	num = 0;
	min = 1;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	if (str[i] == '\0')
		error("Error\nWhere are your arguments? :)");
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = num * 10;
		num = num + str[i] - '0';
		i++;
		if ((num > 2147483648 && min == -1 ) || (num > 2147483647 && min == 1))
			error("Error\nOutside int range");
	}
	if (str[i] != '\0')
		error("Error\nNon numeric argument");
	if (num == 0 && min == -1)
		error("Error\nWhat? -0? Really?");
	return (num * min);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void print_stack(t_stack s)
{
    int i = 0;
    t_list *lst = s.a;
    	while(i < s.size_a)
	{
		printf("A:%d -> %d, markup result->  %d\n", lst->data, lst->index, lst->mp_result);
    	lst = lst->next;
	    i++;
	}
}

int		find_max_a(t_stack*	s)
{
	int max_el = 0;
	int i;
	t_list *list;

	list = s->a;
	i = 0;
	while(i < s->size_a)
	{
		
		if(list->index > list->next->index )
		{
			//printf("asddvvb %d\n", max_el);
			max_el = list->index;
		}
		i++;
		list = list->next;
	}
	
	return(max_el);
}

int		find_max_true_a(t_stack *s)
{
	int max_el;
	int i;
	int max_el_index;
	t_list *list;

	list = s->a;
	i = 0;
	while(i < s->size_a)
	{
		if(list->next->index > list->index)
		{
			max_el = list->next->index;
			max_el_index = list->next->true_index;
		}
		i++;
		list = list->next;
	}
	
	return(max_el_index);
}

int		find_min_a(t_stack*	s)
{
	int min_el = 0;
	int i;
	t_list *list;

	list = s->a;
	i = 0;
	while(i < s->size_a)
	{
		if(list->next->index < list->index)
		{
			min_el = list->next->index;
		}
		i++;
		list = list->next;
	}
	
	return(min_el);
}

int		find_min_true_a(t_stack *s)
{
	int min_el;
	int i;
	int min_el_index;
	t_list *list;

	list = s->a;
	i = 0;
	while(i < s->size_a)
	{
		if(list->next->index < list->index)
		{
			min_el = list->next->index;
			min_el_index = list->next->true_index;
		}
		i++;
		list = list->next;
	}
	
	return(min_el_index);
}

int		find_min_b(t_stack*	s)
{
	int min_el;
	int i;
	t_list *list;

	list = s->b;
	i = 0;
	while(i < s->size_b)
	{
		if(list->next->index < list->index)
		{
			min_el = list->next->index;
		}
		i++;
		list = list->next;
	}
	return(min_el);
}

void		free_stack_a(t_stack *s)
{
	int 	i;
	t_list	*tmp;
	t_list	*del;

	i = 0;
	tmp = s->a;
	while (i < s->size_a)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		i++;
	}
	free(s);
}

void		free_stack_b(t_stack *s)
{
	int i;
	i = 0;
	t_list *tmp;
	t_list * del;

	tmp = s->b;
	while (i < s->size_b)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		i++;
	}
	free(s);
}