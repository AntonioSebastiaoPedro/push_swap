/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:12:54 by ansebast          #+#    #+#             */
/*   Updated: 2024/10/09 21:00:49 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*last_prev;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = ft_lstlast(*a);
	last_prev = ft_lstlastprev(*a);
	last->next = *a;
	*a = last;
	last_prev->next = NULL;
	ft_lstupdateindx(*a);
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*last_prev;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last = ft_lstlast(*b);
	last_prev = ft_lstlastprev(*b);
	last->next = *b;
	*b = last;
	last_prev->next = NULL;
	ft_lstupdateindx(*b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
