/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:16:48 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/28 21:52:07 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstupdateindx(t_stack *head)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = head;
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

int	ft_lstgetindex(t_stack **head, t_stack *value)
{
	t_stack	*current;

	current = *head;
	while (current != NULL)
	{
		if (current == value)
			return (value->index);
		current = current->next;
	}
	return (-1);
}

t_stack	*ft_lstmax(t_stack *head)
{
	t_stack	*max_node;

	max_node = head;
	while (head != NULL)
	{
		if (head->value > max_node->value)
			max_node = head;
		head = head->next;
	}
	return (max_node);
}

void	sort_small_stack(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
		{
			sa(a);
			printf("sa\n");
		}
	}
	else if (ft_lstsize(*a) == 3)
	{
		first = *a;
		second = first->next;
		third = second->next;
		if (first->value > second->value && second->value > third->value)
		{
			ra(a);
			printf("ra\n");
			sa(a);
			printf("sa\n");
			return ;
		}
		else if (first->value > second->value && first->value < third->value)
		{
			sa(a);
			printf("sa\n");
			return ;
		}
		else if (first->value > third->value && second->value < third->value)
		{
			ra(a);
			printf("ra\n");
			return ;
		}
		else if (first->value > third->value && first->value < second->value)
		{
			rra(a);
			printf("rra\n");
			return ;
		}
		else if (second->value > third->value && first->value < second->value)
		{
			rra(a);
			printf("rra\n");
			sa(a);
			printf("sa\n");
			return ;
		}
	}
}

t_stack	*find_successor(t_stack *a, int value)
{
	t_stack	*suces;
	t_stack	*node;

	suces = NULL;
	node = a;
	while (node != NULL)
	{
		if (node->value > value)
		{
			if (!suces || suces->value > node->value)
				suces = node;
		}
		node = node->next;
	}
	if (suces == NULL)
		suces = ft_lstmin(a);
	return (suces);
}

int	calc_cost(t_stack **stack, t_stack *current)
{
	int	cost;
	int	index;
	int	size;

	index = ft_lstgetindex(stack, current);
	size = ft_lstsize(*stack);
	if (index <= (size / 2))
		cost = index;
	else
		cost = size - index;
	return (cost);
}

int	total_cost(t_stack **a, t_stack *value_a, t_stack **b, t_stack *value_b)
{
	if (check_diretion(a, value_a, b, value_b) == 1)
	{
		if (calc_cost(a, value_a) >= calc_cost(b, value_b))
			return (calc_cost(a, value_a));
		else
			return (calc_cost(b, value_b));
	}
	return (calc_cost(a, value_a) + calc_cost(b, value_b));
}

int	check_mov(t_stack **a, t_stack *value)
{
	int	local;
	int	index;
	int	size;

	index = ft_lstgetindex(a, value);
	size = ft_lstsize(*a);
	if (index <= (size / 2))
		local = 0;
	else
		local = 1;
	return (local);
}

int	check_diretion(t_stack **a, t_stack *value_a, t_stack **b, t_stack *value_b)
{
	if (check_mov(a, value_a) == check_mov(b, value_b))
		return (1);
	return (0);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	t_stack	*current;
	t_stack	*temp;
	t_stack	*preces;
	t_stack	*right;
	int		cost_a;
	int		cost_b;
	int		count;

	right = NULL;
	
	
	while (ft_lstsize(*a) > 3)
	{
		pb(a, b);
		printf("pb\n");
	}
        sort_small_stack(a);
	temp = *b;
	while (temp != NULL)
	{
		right = NULL;
		current = temp;
		while (current != NULL)
		{
			preces = find_successor(*a, current->value);
			if (right == NULL)
			{
				right = current;
			}
			else if (total_cost(a, find_successor(*a, right->value), b, right)
                                                >
                                total_cost(a, preces, b, current))
			{
				right = current;
			}
			current = current->next;
		}
                preces = find_successor(*a, right->value);
		if (check_diretion(a, preces, b, right) == 1)
		{
			if (check_mov(b, right) == 0)
			{
				cost_a = calc_cost(a, preces);
				cost_b = calc_cost(b, right);
				if (cost_a >= cost_b)
				{
					while (cost_b)
					{
						rr(a, b);
						printf("rr\n");
						cost_a--;
						cost_b--;
					}
					while (cost_a--)
					{
						ra(a);
						printf("ra\n");
					}
				}
				else
				{
					while (cost_a)
					{
						rr(a, b);
						printf("rr\n");
						cost_a--;
						cost_b--;
					}
					while (cost_b--)
					{
						rb(b);
						printf("rb\n");
					}
				}
				pa(a, b);
				printf("pa\n");
			}
			else
			{
				cost_a = calc_cost(a, preces);
				cost_b = calc_cost(b, right);
				if (cost_a >= cost_b)
				{
					while (cost_b)
					{
						rrr(a, b);
						printf("rrr\n");
						cost_a--;
						cost_b--;
					}
					while (cost_a--)
					{
						rra(a);
						printf("rra\n");
					}
				}
				else
				{
					while (cost_a)
					{
						rrr(a, b);
						printf("rrr\n");
						cost_a--;
						cost_b--;
					}
					while (cost_b--)
					{
						rrb(b);
						printf("rrb\n");
					}
				}
				pa(a, b);
				printf("pa\n");
			}
		}
		else
		{
			if (check_mov(a, preces) == 0)
			{
				count = calc_cost(a, preces);
				while (count)
				{
					ra(a);
					printf("ra\n");
                                        count--;
				}
			}
			else
			{
				count = calc_cost(a, preces);
				while (count)
				{
					rra(a);
					printf("rra\n");
                                        count--;
				}
			}
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
		temp = *b;
	}
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