/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:12:54 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/27 16:43:22 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rra(t_stack **a)
{
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
	{
		return ;
	}
	last = ft_lstlast(*a);
	last->previous->next = NULL;
	last->previous = NULL;       
	last->next = *a;            
	(*a)->previous = last;      
	*a = last;                  
	ft_lstupdateindx(*a);       
}

void	rrb(t_stack **b)
{
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
	{
		return ;
	}
	last = ft_lstlast(*b);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *b;
	*b = last;
	(*b)->next->previous = *b;
	ft_lstupdateindx(*b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}