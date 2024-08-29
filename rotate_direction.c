/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:05:37 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 10:06:42 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate_direction(t_stack **a, t_stack *successor, t_stack **b,
		t_stack *right)
{
	int	cost_a;
	int	cost_b;

	if (check_direction(a, successor, b, right) == 1)
	{
		cost_a = 0;
		cost_b = 0;
		if (check_mov(b, right) == 0)
		{
			rotate_successor_right(cost_a, a, successor, cost_b, b, right);
			pa(a, b);
			printf("pa\n");
		}
		else
		{
			rev_rotate_successor_right(cost_a, a, successor, cost_b, b, right);
			pa(a, b);
			printf("pa\n");
		}
	}
	else
	{
		calc_rotate_succesor(a, successor);
		calc_rotate_right(b, a, right);
	}
}

void	rotate_successor_right(int cost_a, t_stack **a, t_stack *successor,
		int cost_b, t_stack **b, t_stack *right)
{
	cost_a = calc_cost(a, successor);
	cost_b = calc_cost(b, right);
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		printf("rr\n");
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		ra(a);
		printf("ra\n");
		cost_a--;
	}
	while (cost_b > 0)
	{
		rb(b);
		printf("rb\n");
		cost_b--;
	}
}

void	rev_rotate_successor_right(int cost_a, t_stack **a, t_stack *successor,
		int cost_b, t_stack **b, t_stack *right)
{
	cost_a = calc_cost(a, successor);
	cost_b = calc_cost(b, right);
	while (cost_a > 0 && cost_b > 0)
	{
		rrr(a, b);
		printf("rrr\n");
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rra(a);
		printf("rra\n");
		cost_a--;
	}
	while (cost_b > 0)
	{
		rrb(b);
		printf("rrb\n");
		cost_b--;
	}
}