/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:16:48 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/30 15:30:54 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*get_right(t_stack **a, t_stack **b, t_stack *head)
{
	t_stack	*current;
	t_stack	*succesor;
	t_stack	*right;

	current = head;
	right = NULL;
	while (current != NULL)
	{
		succesor = find_successor(*a, current->value);
		if (right == NULL)
		{
			right = current;
		}
		else if (total_cost(a, find_successor(*a, right->value), b,
				right) > total_cost(a, succesor, b, current))
		{
			right = current;
		}
		current = current->next;
	}
	return (right);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*preces;
	t_stack	*right;

	while (ft_lstsize(*a) > 3)
	{
		pb(a, b);
		printf("pb\n");
	}
	sort_small_stack(a);
	temp = *b;
	while (temp != NULL)
	{
		right = get_right(a, b, temp);
		preces = find_successor(*a, right->value);
		rotate_direction(a, preces, b, right);
		temp = *b;
	}
	sort_min(a);
}

void	sort_min(t_stack **a)
{
	t_stack	*min_node;

	min_node = ft_lstmin(*a);
	if (check_mov(a, min_node) == 0)
	{
		while (*a != min_node)
		{
			ra(a);
			printf("ra\n");
		}
	}
	else
	{
		while (*a != min_node)
		{
			rra(a);
			printf("rra\n");
		}
	}
}

void	add_to_stack(t_stack **a, char *val)
{
	long value;
	t_stack *new_node;

        
        if (!ft_isint(val))
        {
                write(1, "Error\n", 6);
                exit(1);
        }
	value = ft_atoi(val);
	new_node = ft_lstnew(value);
	if (!new_node)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	ft_lstadd_back(a, new_node);
}