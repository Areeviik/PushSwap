/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:58:37 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/04 12:58:54 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int info, int index)
{
	t_list	*l;

	if (!(l = (t_list *)malloc(sizeof(t_list))))
		return (0);
	l->data = info;
	if (index == -2)
		l->index = -1;
	else
		l->index = index;
	l->next = l;
	l->previous = l;
	return (l);
}

void	ft_lstadd_front(t_list **lst, t_list *neww)
{
	if (*lst)
	{
		neww->previous = (*lst)->previous;
		neww->next = *lst;
		((*lst)->previous)->next = neww;
		(*lst)->previous = neww;
		*lst = neww;
	}
	else
		*lst = neww;
}

void	ft_lstdel_front(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->previous->next = *lst;
	(*lst)->previous = tmp->previous;
	free(tmp);
}
