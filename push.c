/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:10 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/21 12:50:52 by ansebast         ###   ########.fr       */
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
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

// void push_operation(t_list **operations, char *operation)
// {
//     t_list *new_node = ft_lstnew(operation);
//     if (new_node)
//     {
//         new_node->next = *operations;
//         *operations = new_node;
//     }
// }