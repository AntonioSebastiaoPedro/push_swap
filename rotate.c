/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:01:51 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/16 16:00:07 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = ft_lstlast(stack);
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}