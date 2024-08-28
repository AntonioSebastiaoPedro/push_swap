/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:10 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/28 09:54:37 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	if (*b == NULL)
		return ;
	top_b = *b;
        *b = top_b->next;
        top_b->next = *a;
        *a = top_b;

        ft_lstupdateindx(*a);
        ft_lstupdateindx(*b);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	if (*a == NULL)
		return ;
	top_a = *a;
        *a = top_a->next;
        top_a->next = *b;
        *b = top_a;
        ft_lstupdateindx(*a);
        ft_lstupdateindx(*b);
}