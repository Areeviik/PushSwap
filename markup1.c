/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:47:38 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/26 15:47:40 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     markup(t_stack *s)
{
    t_list  *list;
    int     i;
    int     index;
    int     next_index;
    int     count;
    int     tmp_index;
    int     tmp_count;
    int     mp_head;
    int     tmp_index_sec;

    list = s->a;
    index = list->index;
    i = 0;
    count  = 1;
    tmp_count = 0;
    mp_head = list->index;
    while (i < s->size_a)
    {
        tmp_index = list->index;
        tmp_index_sec = tmp_index;
        next_index = list->next->index;
        list = list->next;
        
        while(tmp_index != list->index)
        {  
            if (tmp_index < list->index)
            {
                count++;
                tmp_index = list->index;
                
            } 
            list = list->next;
        }
        if(count >= tmp_count)
        {
            if (count == tmp_count)
            {
                
                if(tmp_index_sec < mp_head)
                {
                    mp_head = tmp_index_sec;
                }
                    
            }
            else
            {
                mp_head = tmp_index_sec;
            }
            tmp_count = count;
        } 
        count = 1;
        while(list->index != next_index)
            list = list->next;
        ++i;
    }
    list->count = tmp_count;
    return(mp_head);
}

void     markup_bool(t_stack *s)
{
    t_list *list;

    list = s->a;
    int m;
    int temp_max = 0;
    m = markup(s);

    while (list->index != m)
        list = list->next;
    
    list->mp_result = 1;
    temp_max = m;
    list = list->next;
    while (list->index != m)
    {
        if (list->index > temp_max)
        {
            temp_max = list->index;
            list->mp_result = 1;
        }
        else
            list->mp_result = 0;
        list = list->next;
    }
}
