/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:32:38 by ansebast          #+#    #+#             */
/*   Updated: 2024/10/10 08:26:12 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		check_direction(t_stack **a, t_stack *value_a, t_stack **b,
			t_stack *value_b);
int		check_mov(t_stack **a, t_stack *value);
int		calc_cost(t_stack **stack, t_stack *current);
int		total_cost(t_stack **a, t_stack *value_a, t_stack **b,
			t_stack *value_b);
void	validate_arguments(int argc, char **argv, t_stack **a);
void	sort_small_stack(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	add_to_stack(t_stack **a, int val);
void	sort_min(t_stack **a);
void	calc_rotate_succesor(t_stack **a, t_stack *succesor);
void	calc_rotate_right(t_stack **b, t_stack **a, t_stack *right);
void	rotate_direction(t_stack **a, t_stack *successor, t_stack **b,
			t_stack *right);
void	rotate_successor_right(t_stack **a, t_stack *successor, t_stack **b,
			t_stack *right);
void	rev_rotate_successor_right(t_stack **a, t_stack *successor, t_stack **b,
			t_stack *right);

#endif
