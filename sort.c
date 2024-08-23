/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:16:48 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/23 14:56:15 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
        t_stack	*current;
        t_stack	*last;
	int     len_stack;
        
	while (*a != NULL)
	{
                current = *a;
		min_node = *a;
                while (current != NULL)
                {
                        if (current->value < min_node->value)
                                min_node = current;
                        current = current->next;
                }
                len_stack = ft_lstsize(*a);
                last = ft_lstlast(*a);
                int first = len_stack - min_node->index + 1;
                if (first > 0 && ((first) - (len_stack / 2) >= 0))
                {
                        while (*a != min_node)
                        {
                                ra(a);
                                printf("ra\n");
                        }       
                }
                else
                {
                        while (last != min_node )
                        {
                                rra(a);
                                printf("rra\n");
                                last = last->previous;
                        }
                }
		pb(a, b);
		printf("pb\n");
	}
	while (*b != NULL)
	{
		pa(a, b);
		printf("pa\n");
	}
}

void	add_to_stack(t_stack **a, int value)
{
	t_stack *new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	if (!*a)
	{
		*a = new_node;
		return ;
	}
        
        ft_lstadd_back(a, new_node);
}