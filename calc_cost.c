/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:02:50 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/31 21:19:57 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_cost(t_stack **stack, t_stack *current)
{
	int	cost;
	int	index;
	int	size;

	index = ft_lstgetindex(stack, current);
	size = ft_lstsize(*stack);
	if (index <= (size / 2))
		cost = index;
	else
		cost = size - index;
	return (cost);
}

int	total_cost(t_stack **a, t_stack *value_a, t_stack **b, t_stack *value_b)
{
	if (check_direction(a, value_a, b, value_b) == 1)
	{
		if (calc_cost(a, value_a) >= calc_cost(b, value_b))
			return (calc_cost(a, value_a));
		else
			return (calc_cost(b, value_b));
	}
	return (calc_cost(a, value_a) + calc_cost(b, value_b));
}

void	calc_rotate_right(t_stack **b, t_stack **a, t_stack *right)
{
	int	count;

	if (check_mov(b, right) == 0)
	{
		count = calc_cost(b, right);
		while (count--)
		{
			rb(b);
			ft_putstr("rb\n");
		}
		pa(a, b);
		ft_putstr("pa\n");
	}
	else
	{
		count = calc_cost(b, right);
		while (count--)
		{
			rrb(b);
			ft_putstr("rrb\n");
		}
		pa(a, b);
		ft_putstr("pa\n");
	}
}

void	calc_rotate_succesor(t_stack **a, t_stack *succesor)
{
	int count;

	if (check_mov(a, succesor) == 0)
	{
		count = calc_cost(a, succesor);
		while (count)
		{
			ra(a);
			ft_putstr("ra\n");
			count--;
		}
	}
	else
	{
		count = calc_cost(a, succesor);
		while (count)
		{
			rra(a);
			ft_putstr("rra\n");
			count--;
		}
	}
}