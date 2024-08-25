/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:16:48 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/25 13:01:21 by ansebast         ###   ########.fr       */
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

t_stack	*find_predecessor(t_stack *b, int value)
{
	t_stack	*prev;
	t_stack	*node;

	prev = NULL;
        node = b;
	while (node != NULL)
	{
		if (node->value < value)
		{
			if (!prev || prev->value < node->value)
				prev = node;
		}
		node = node->next;
	}
	if (prev == NULL)
		prev = ft_lstmax(b);
	return (prev);
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
	if (size % 2 != 0)
		size++;
	if ((index + 1) <= (size / 2))
		cost = index;
	else
	{
		if (size % 2 == 0)
			cost = size - index;
		else
			cost = size - index + 1;
	}
	return (cost);
}

int	total_cost(t_stack **a, t_stack *value_a, t_stack **b, t_stack *value_b)
{
	int	cost;

	if (check_diretion(a, value_a, b, value_b) && calc_cost(a,
			value_a) == calc_cost(b, value_b))
		cost = calc_cost(a, value_a);
	else
		cost = calc_cost(a, value_a) + calc_cost(b, value_b);
	return (cost);
}

int	check_mov(t_stack **a, t_stack *value)
{
	int	local;
	int	index;
	int	size;

	index = ft_lstgetindex(a, value);
	size = ft_lstsize(*a);
	if (size % 2 != 0)
		size++;
	if ((index + 1) <= (size / 2))
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
	int		len_stack;
	int		tr;
	int		fal;
	t_stack	*preces;
	t_stack	*right = NULL;

	if (ft_lstsize(*a) <= 5)
	{
		while (*a != NULL)
		{
			len_stack = ft_lstsize(*a);
			if (len_stack <= 3)
			{
				sort_small_stack(a);
				break ;
			}
			current = *a;
			min_node = *a;
			while (current != NULL)
			{
				if (current->value < min_node->value)
					min_node = current;
				current = current->next;
			}
			tr = len_stack - (min_node->index + 1);
			fal = tr - len_stack / 2;
			if (fal >= 0)
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
			pb(a, b);
			printf("pb\n");
			// ft_lstprint(*a);
		}
	}
	else
	{
		pb(a, b);
		printf("pb\n");
		pb(a, b);
		printf("pb\n");
		temp = *a;
		while (temp != NULL)
		{
			len_stack = ft_lstsize(*a);
			if (len_stack <= 3)
			{
				sort_small_stack(a);
				break ;
			}
			current = temp;
			while (current != NULL)
			{
				preces = find_predecessor(*b, current->value);
                                printf("=================\n");
                                if (!right)
                                {
                                        printf("EntroA");
                                        // printf("EntroA %d \n", current->value);
                                        right = current;
                                }
				else if (total_cost(a, right, b, find_predecessor(*b, right->value)) > total_cost(a,
						current, b, preces))
                                {
                                        // printf("EntroB");
                                        // printf("EntroB %d \n", current->value);
                                        // right = current;
                                }
                                printf("NEXT");
				current = current->next;
			}
			preces = find_predecessor(*b, right->value);
			if (check_diretion(a, right, b, preces) && calc_cost(a,
					right) == calc_cost(b, preces))
			{
				if (check_mov(a, right) == 0)
				{
					while (right->index != 0)
					{
						rr(a, b);
						printf("rr\n");
					}
					pb(a, b);
					printf("pb\n");
				}
				else
				{
					while (right->index != 0)
					{
						rrr(a, b);
						printf("rrr\n");
					}
					pb(a, b);
					printf("pb\n");
				}
			}
			else
			{
				if (check_mov(a, right) == 0)
				{
					while (right->index != 0)
					{
						ra(a);
						printf("ra\n");
					}
					pb(a, b);
					printf("pb\n");
				}
				else
				{
					while (right->index != 0)
					{
						rra(a);
						printf("rra\n");
					}
				}
				if (check_mov(b, preces) == 0)
				{
					while (preces->index != 0)
					{
						rb(b);
						printf("rb\n");
					}
					pb(a, b);
					printf("pb\n");
				}
				else
				{
					while (preces->index != 0)
					{
						rrb(b);
						printf("rrb\n");
					}
					pb(a, b);
					printf("pb\n");
				}
			}
			temp = temp->next;
		}
	}
	temp = *b;
	while (temp != NULL)
	{
		len_stack = ft_lstsize(*b);
		current = temp;
		while (current != NULL)
		{
			preces = find_successor(*a, current->value);
			if (!right || total_cost(b, right, a, preces) > total_cost(b,
					current, a, preces))
				right = current;
			current = current->next;
		}
		preces = find_successor(*a, right->value);
		if (check_diretion(b, right, a, preces) && calc_cost(b,
				right) == calc_cost(a, preces))
		{
			if (check_mov(b, right) == 0)
			{
				while (right->index != 0)
				{
					rr(a, b);
					printf("rr\n");
				}
				pa(a, b);
				printf("pa\n");
			}
			else
			{
				while (right->index != 0)
				{
					rrr(a, b);
					printf("rrr\n");
				}
				pa(a, b);
				printf("pa\n");
			}
		}
		else
		{
			if (check_mov(b, right) == 0)
			{
				while (right->index != 0)
				{
					rb(b);
					printf("rb\n");
				}
				pa(a, b);
				printf("pa\n");
			}
			else
			{
				while (right->index != 0)
				{
					rrb(b);
					printf("rrb\n");
				}
			}
			if (check_mov(a, preces) == 0)
			{
				while (preces->index != 0)
				{
					ra(a);
					printf("ra\n");
				}
				pa(a, b);
				printf("pa\n");
			}
			else
			{
				while (preces->index != 0)
				{
					rra(a);
					printf("rra\n");
				}
				pa(a, b);
				printf("pa\n");
			}
		}
		temp = temp->next;
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