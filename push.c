/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:10 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/24 08:11:58 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	if (*b == NULL)
	{
		return ;
	}
	top_b = *b;
	*b = (*b)->next;
	if (*b != NULL)
	{
		(*b)->previous = NULL;
	}
	top_b->next = *a;
	if (*a != NULL)
	{
		(*a)->previous = top_b;
	}
	top_b->previous = NULL;
	*a = top_b;

        ft_lstupdateindx(*a);
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
	{
		return ;
	}

	t_stack *top_a = *a;
	*a = (*a)->next;

	if (*a != NULL)
	{
		(*a)->previous = NULL;
	}

	top_a->next = *b;
	if (*b != NULL)
	{
		(*b)->previous = top_a;
	}
	top_a->previous = NULL;
	*b = top_a;

        ft_lstupdateindx(*a);
}