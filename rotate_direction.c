/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:05:37 by ansebast          #+#    #+#             */
/*   Updated: 2024/10/09 22:13:25 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_direction(t_stack **a, t_stack *successor, t_stack **b,
		t_stack *right)
{
	if (check_direction(a, successor, b, right) == 1)
	{
		if (check_mov(b, right) == 0)
		{
			rotate_successor_right(a, successor, b, right);
			pa(a, b);
			ft_putstr_fd("pa\n", 1);
		}
		else
		{
			rev_rotate_successor_right(a, successor, b, right);
			pa(a, b);
			ft_putstr_fd("pa\n", 1);
		}
	}
	else
	{
		calc_rotate_succesor(a, successor);
		calc_rotate_right(b, a, right);
	}
}

void	rotate_successor_right(t_stack **a, t_stack *successor, t_stack **b,
		t_stack *right)
{
	int	cost_a;
	int	cost_b;

	cost_a = calc_cost(a, successor);
	cost_b = calc_cost(b, right);
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		ft_putstr_fd("rr\n", 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		ra(a);
		ft_putstr_fd("ra\n", 1);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rb(b);
		ft_putstr_fd("rb\n", 1);
		cost_b--;
	}
}

void	rev_rotate_successor_right(t_stack **a, t_stack *successor, t_stack **b,
		t_stack *right)
{
	int	cost_a;
	int	cost_b;

	cost_a = calc_cost(a, successor);
	cost_b = calc_cost(b, right);
	while (cost_a > 0 && cost_b > 0)
	{
		rrr(a, b);
		ft_putstr_fd("rrr\n", 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rra(a);
		ft_putstr_fd("rra\n", 1);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rrb(b);
		ft_putstr_fd("rrb\n", 1);
		cost_b--;
	}
}
