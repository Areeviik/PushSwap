/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_sec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:52:27 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/13 16:52:53 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	*lst = (*lst)->next;

}

void	rr(t_stack *s) 
{
	rotate(&s->a);
	rotate(&s->b);
}

void	rrotate(t_list	**lst)
{
	*lst = (*lst)->previous;
}

void	rrr(t_stack *s)
{
	rrotate(&s->a);
	rrotate(&s->b);

}
