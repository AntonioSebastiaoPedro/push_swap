/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_direction.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:05:09 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 08:14:57 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_direction(t_stack **a, t_stack *value_a, t_stack **b,
		t_stack *value_b)
{
	if (check_mov(a, value_a) == check_mov(b, value_b))
		return (1);
	return (0);
}

int	check_mov(t_stack **a, t_stack *value)
{
	int	local;
	int	index;
	int	size;

	index = ft_lstgetindex(a, value);
	size = ft_lstsize(*a);
	if (index <= (size / 2))
		local = 0;
	else
		local = 1;
	return (local);
}
