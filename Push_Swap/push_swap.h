/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:14:52 by akhachat          #+#    #+#             */
/*   Updated: 2021/08/02 16:15:43 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_commands{
	int				ss;
	int				rr;
	int 			ra;
	int 			rb;
	int				rrr;
	int				rra;
	int				rrb;
}				t_commands;

typedef struct		s_list
{
	int				ss;
	int				rr;
	int 			ra;
	int 			rb;
	int				rrr;
	int				rra;
	int				rrb;
	int				data;
	int				index;
	struct	s_list	*next;
	struct	s_list	*previous;
	int				mp_result;
	int				count;
	int				count_of_b;
	int				markup_head;
	int				true_index;
	int				flagik;
	int				ayitexe;
}					t_list;

typedef struct 		s_stack
{
	t_list	*a;
	t_list	*b;

	int		size_a;
	int		size_b;
}					t_stack;


t_list			*ft_lstnew(int info, int index);
void			ft_lstadd_front(t_list **lst, t_list *neww);
void			ft_lstdel_front(t_list **lst);
void			swap(t_list *lst);
void			ss(t_stack *s);
void			pa(t_stack *s);
void			pb(t_stack *s);
void			rotate(t_list **lst);
void			rr(t_stack *s);
void			rrotate(t_list	**lst);
void			rrr(t_stack *s);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
void    		parsing1(t_stack *s,char **argv);
int				error(char *str);
unsigned long	ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			parsing2(t_stack *s, int argc, char **argv);
void    		indexing(t_stack *s);
int     		find_min(t_list *list);
void			alg_2(t_stack *s);
void    		alg_3(t_stack *s);
void			alg_4(t_stack *s);
void			alg_5(t_stack *s);
int				is_sorted(t_stack *s);
int    			markup(t_stack *s);
void     		markup_bool(t_stack *s);
void    		alg_100(t_stack *s);
void			pushtob(t_stack *s);
// int             sa_is_needed(t_stack *s);
int     	   	there_is_false(t_stack *stack);
void			pushtoa(t_stack *s);
int				find_min_a(t_stack*	s);
int				find_min_b(t_stack*	s);
void    		to_the_topB(t_stack *s);
void    		trueindexingA(t_stack *s);
void    		trueindexingB(t_stack *s);
int 	       	findtheplace(t_stack *s);
int				find_min_true_a(t_stack *s);
int				find_max_true_a(t_stack *s);
int				find_max_a(t_stack*	s);
void        	find_size(t_stack *s, int b_item, int a_item);
void        	legacy(t_stack *s);
void			doFunctions(int minimum, t_stack *s, int j, t_commands *commands);
void 			replace_a(t_stack *s);
void			free_stack_a(t_stack *s);
void			free_stack_b(t_stack *s);



#endif
