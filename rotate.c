/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:01:51 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 08:46:48 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	*a = first->next;
	last = ft_lstlast(*a);
	last->next = first;
	first->next = NULL;
	ft_lstupdateindx(*a);
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	*b = first->next;
	last = ft_lstlast(*b);
	last->next = first;
	first->next = NULL;
	ft_lstupdateindx(*b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
