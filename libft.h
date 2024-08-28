/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:32:38 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/28 21:58:43 by ansebast         ###   ########.fr       */
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
int					check_diretion(t_stack **a, t_stack *value_a, t_stack **b,
						t_stack *value_b);
int					is_sorted(t_stack *stack);
void				swap_nodes(t_stack **head, t_stack *node1, t_stack *node2);
void				ft_lstadd_front(t_stack **head, t_stack *new_node);
void				ft_lstiter(t_stack *head, void (*f)(int));
void				ft_lstdelone(t_stack *node);
void				ft_lstclear(t_stack **head);
void				ft_lstprint(t_stack *head);
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
void				ft_lstupdateindx(t_stack *head);
void				ft_lstadd_back(t_stack **head, t_stack *new_node);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstmin(t_stack *head);
t_stack				*ft_lstlast(t_stack *head);
t_stack				*ft_lstlastprev(t_stack *head);

#endif
