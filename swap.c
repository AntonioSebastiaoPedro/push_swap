/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:37 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 10:18:28 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	ft_lstupdateindx(*a);
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	ft_lstupdateindx(*b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
