/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:53:55 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/01 00:19:51 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_small_stack(t_stack **a)
{
	t_stack	*max;

	if (ft_lstsize(*a) == 3)
	{
		max = ft_lstmax(*a);
		if (*a == max)
		{
			ra(a);
			ft_putstr("ra\n");
		}
		else if ((*a)->next == max)
		{
			rra(a);
			ft_putstr("rra\n");
		}
		if ((*a)->value > (*a)->next->value)
		{
			sa(a);
			ft_putstr("sa\n");
		}
	}
}
