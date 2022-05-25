/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:06:17 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/07 14:06:18 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst)
{
	int	tmp;

	if (lst && lst->next)
	{
		tmp = lst->data;
		lst->data = ((lst)->next)->data;
		((lst)->next)->data = tmp;
		tmp = lst->index;
		lst->index = ((lst)->next)->index;
		((lst)->next)->index = tmp;
	}
}

void	ss(t_stack *s)
{
	swap(s->a);
	swap(s->b);
}

void	pa(t_stack *s)
{
	t_list	*tmp;

	if (s->b)
	{
		tmp = ft_lstnew(s->b->data, s->b->index);
		ft_lstadd_front(&s->a, tmp);
		ft_lstdel_front(&s->b);
		s->size_b--;
		s->size_a++;
	}

}

void	pb(t_stack *s)
{
	t_list	*tmp;

	if (s->a)
	{
		tmp = ft_lstnew(s->a->data, s->a->index);
		ft_lstadd_front(&s->b, tmp);
		ft_lstdel_front(&s->a);
		s->size_a--;
		s->size_b++;
	}
}
