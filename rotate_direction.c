/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:05:37 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/01 00:20:31 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate_direction(t_stack **a, t_stack *successor, t_stack **b,
		t_stack *right)
{
	if (check_direction(a, successor, b, right) == 1)
	{
		if (check_mov(b, right) == 0)
		{
			rotate_successor_right(a, successor, b, right);
			pa(a, b);
			ft_putstr("pa\n");
		}
		else
		{
			rev_rotate_successor_right(a, successor, b, right);
			pa(a, b);
			ft_putstr("pa\n");
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
		ft_putstr("rr\n");
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		ra(a);
		ft_putstr("ra\n");
		cost_a--;
	}
	while (cost_b > 0)
	{
		rb(b);
		ft_putstr("rb\n");
		cost_b--;
	}
}

void	rev_rotate_successor_right(t_stack **a, t_stack *successor, t_stack **b,
		t_stack *right)
{
	int cost_a;
	int cost_b;

	cost_a = calc_cost(a, successor);
	cost_b = calc_cost(b, right);
	while (cost_a > 0 && cost_b > 0)
	{
		rrr(a, b);
		ft_putstr("rrr\n");
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rra(a);
		ft_putstr("rra\n");
		cost_a--;
	}
	while (cost_b > 0)
	{
		rrb(b);
		ft_putstr("rrb\n");
		cost_b--;
	}
}