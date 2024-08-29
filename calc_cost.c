/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:02:50 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 08:14:05 by ansebast         ###   ########.fr       */
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
	if (check_diretion(a, value_a, b, value_b) == 1)
	{
		if (calc_cost(a, value_a) >= calc_cost(b, value_b))
			return (calc_cost(a, value_a));
		else
			return (calc_cost(b, value_b));
	}
	return (calc_cost(a, value_a) + calc_cost(b, value_b));
}