/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:19:57 by akhachat          #+#    #+#             */
/*   Updated: 2021/07/22 15:19:59 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// int i = 1;
	// while (i)
	// {
	// 	printf("smth");
	// 	i++;
	
	t_stack	s;
	
	s.size_a = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		parsing1(&s, argv);
	else
		parsing2(&s, argc, argv);
	if (is_sorted(&s))
		return (0);
	else
	if(s.size_a == 2)
		alg_2(&s);
	else if(s.size_a == 3)
		alg_3(&s);
	else if (s.size_a == 4)
		alg_4(&s);
	else if (s.size_a == 5)
		alg_5(&s);
	else if (s.size_a > 5)
		alg_100(&s);
	
	// int i = 0;
	// while(i < s.size_a)
	// {
	// 	printf("A:%d ->true index  %d, -> index  %d, markup result->  %d\n", s.a->data, s.a->true_index, s.a->index, s.a->mp_result);
    // 	s.a = s.a->next;
	//     i++;
	// }
	// i = 0;
	// while(i < s.size_b)
	// {
	// 	printf("B:%d ->true index  %d, -> index  %d, markup result->  %d - > count of b %d\n", s.b->data, s.b->true_index, s.b->index, s.b->mp_result, s.b->count_of_b);
    // 	s.b = s.b->next;
	//     i++;
	// }
	// free_stack_a(&s);
	// free_stack_b(&s);
	// freen chmoranal, aranqnerum el
	return (0);
}

