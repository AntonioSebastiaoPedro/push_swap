/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:53:55 by ansebast          #+#    #+#             */
/*   Updated: 2024/10/09 22:13:42 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_stack **a)
{
	t_stack	*max;

	if (ft_lstsize(*a) == 3)
	{
		max = ft_lstmax(*a);
		if (*a == max)
		{
			ra(a);
			ft_putstr_fd("ra\n", 1);
		}
		else if ((*a)->next == max)
		{
			rra(a);
			ft_putstr_fd("rra\n", 1);
		}
		if ((*a)->value > (*a)->next->value)
		{
			sa(a);
			ft_putstr_fd("sa\n", 1);
		}
	}
}
