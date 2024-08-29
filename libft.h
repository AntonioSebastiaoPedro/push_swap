/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:32:38 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 10:15:16 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				value;
	int				index;
	struct t_stack	*next;
}					t_stack;
int					check_direction(t_stack **a, t_stack *value_a, t_stack **b,
						t_stack *value_b);
int					check_mov(t_stack **a, t_stack *value);
int					is_sorted(t_stack *stack);
int					ft_lstsize(t_stack *lst);
int					ft_lstgetindex(t_stack **head, t_stack *value);
int					calc_cost(t_stack **stack, t_stack *current);
int					total_cost(t_stack **a, t_stack *value_a, t_stack **b,
						t_stack *value_b);
void				ft_lstdelone(t_stack *node);
void				ft_lstclear(t_stack **head);
// void				ft_lstprint(t_stack *head);
void				sort_small_stack(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				sort_stack(t_stack **a, t_stack **b);
void				add_to_stack(t_stack **a, int value);
void				ft_putstr(char *s);
void				sort_min(t_stack **a);
void				calc_rotate_succesor(t_stack **a, t_stack *succesor);
void				calc_rotate_right(t_stack **b, t_stack **a, t_stack *right);
void				ft_lstupdateindx(t_stack *head);
void				ft_lstadd_back(t_stack **head, t_stack *new_node);
void				rotate_direction(t_stack **a, t_stack *successor,
						t_stack **b, t_stack *right);
void				rotate_successor_right(int cost_a, t_stack **a,
						t_stack *successor, int cost_b, t_stack **b,
						t_stack *right);
void				rev_rotate_successor_right(int cost_a, t_stack **a,
						t_stack *successor, int cost_b, t_stack **b,
						t_stack *right);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstmin(t_stack *head);
t_stack				*ft_lstlast(t_stack *head);
t_stack				*ft_lstlastprev(t_stack *head);
t_stack				*find_successor(t_stack *a, int value);
t_stack				*get_right(t_stack **a, t_stack **b, t_stack *head);

#endif
