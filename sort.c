/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:16:48 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 09:31:10 by ansebast         ###   ########.fr       */
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

void	rotate_successor_right(int cost_a, t_stack **a, t_stack *successor, int cost_b,
		t_stack **b, t_stack *right)
{
	cost_a = calc_cost(a, successor);
	cost_b = calc_cost(b, right);
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		printf("rr\n");
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		ra(a);
		printf("ra\n");
		cost_a--;
	}
	while (cost_b > 0)
	{
		rb(b);
		printf("rb\n");
		cost_b--;
	}
}

void	rev_rotate_successor_right(int cost_a, t_stack **a, t_stack *successor, int cost_b,
		t_stack **b, t_stack *right)
{
	cost_a = calc_cost(a, successor);
	cost_b = calc_cost(b, right);
	while (cost_a > 0 && cost_b > 0)
	{
		rrr(a, b);
		printf("rrr\n");
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rra(a);
		printf("rra\n");
		cost_a--;
	}
	while (cost_b > 0)
	{
		rrb(b);
		printf("rrb\n");
		cost_b--;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*preces;
	t_stack	*right;
	int		cost_a;
	int		cost_b;

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
		if (check_diretion(a, preces, b, right) == 1)
		{
                        cost_a = 0;
			cost_b = 0;
			if (check_mov(b, right) == 0)
			{
				rotate_successor_right(cost_a, a, preces, cost_b, b, right);
				pa(a, b);
				printf("pa\n");
			}
			else
			{
				rev_rotate_successor_right(cost_a, a, preces, cost_b, b, right);
				pa(a, b);
				printf("pa\n");
			}
		}
		else
		{
			calc_rotate_succesor(a, preces);
			calc_rotate_right(b, a, right);
		}
		temp = *b;
	}
	sort_min(a);
}

void	calc_rotate_right(t_stack **b, t_stack **a, t_stack *right)
{
	int	count;

	if (check_mov(b, right) == 0)
	{
		count = calc_cost(b, right);
		while (count--)
		{
			rb(b);
			printf("rb\n");
		}
		pa(a, b);
		printf("pa\n");
	}
	else
	{
		count = calc_cost(b, right);
		while (count--)
		{
			rrb(b);
			printf("rrb\n");
		}
		pa(a, b);
		printf("pa\n");
	}
}

void	calc_rotate_succesor(t_stack **a, t_stack *succesor)
{
	int	count;

	if (check_mov(a, succesor) == 0)
	{
		count = calc_cost(a, succesor);
		while (count)
		{
			ra(a);
			printf("ra\n");
			count--;
		}
	}
	else
	{
		count = calc_cost(a, succesor);
		while (count)
		{
			rra(a);
			printf("rra\n");
			count--;
		}
	}
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