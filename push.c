/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:10 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/16 16:00:07 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*current;

	if (*src)
	{
		current = *src;
		*src = (*src)->next;
		current->next = *dest;
		*dest = current;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	printf("pb\n");
}