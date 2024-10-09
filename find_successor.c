/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_successor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:01:09 by ansebast          #+#    #+#             */
/*   Updated: 2024/10/09 21:00:46 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_successor(t_stack *a, int value)
{
	t_stack	*suces;
	t_stack	*node;

	suces = NULL;
	node = a;
	while (node != NULL)
	{
		if (node->value > value)
		{
			if (!suces || suces->value > node->value)
				suces = node;
		}
		node = node->next;
	}
	if (suces == NULL)
		suces = ft_lstmin(a);
	return (suces);
}
