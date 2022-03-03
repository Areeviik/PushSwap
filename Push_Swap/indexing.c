/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:00:50 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/13 19:01:00 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     find_min(t_list *list)
{
    int min_el;
    t_list *tmp;
    tmp = list;
    while(tmp->index != -1)
        tmp = tmp->next;
    min_el = tmp->data;
    tmp = list->next;
    while (list->data != tmp->data)
    {
        if (min_el > tmp->data && tmp->index == -1)
            min_el = tmp->data;
        tmp = tmp->next;
    }
    return (min_el);
}

void    indexing(t_stack *s)
{
    int     index;
    int     min;
    t_list  *tmp;

    index = 0;
    while (index < s->size_a)
    {
        tmp = s->a;
        min = find_min(s->a);
        while(tmp->data != min)
            tmp = tmp->next;
        tmp->index = index;
        index++;
    }
}


void    trueindexingB(t_stack *s)
{
    int     index;
    t_list  *tmp;

    tmp = s->b;
    index = 0;
    s->b->true_index = 0;
    
    while (index < s->size_b)
    {
        tmp->true_index = index;
        index++;
        tmp = tmp->next;
    }
}

void    trueindexingA(t_stack *s)
{
    int     index;
    t_list  *tmp;

    tmp = s->a;
    index = 0;
    s->a->true_index = 0;
    
    while (index < s->size_a)
    {
        tmp->true_index = index;
        index++;
        tmp = tmp->next;
    }
}