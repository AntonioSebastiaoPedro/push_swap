/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:16:48 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/24 19:31:37 by ansebast         ###   ########.fr       */
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

	prev = NULL;
	while (b != NULL)
	{
		if (b->value < value)
		{
                        if (!prev || prev->value < b->value)
                                prev = b;
		}
		b = b->next;
	}
	return (prev);
}

int	calculate_cost(t_stack *a, t_stack *b, int value)
{
	int		cost_a = 0, cost_b;
	t_stack	*pred;

	cost_a = 0, cost_b = 0;
	pred = find_predecessor(b, value);
	// Calcular o custo de mover o elemento em 'a' para o topo
	while (a != NULL && a->value != value)
	{
		cost_a++;
		a = a->next;
	}
	// Calcular o custo de mover o antecessor em 'b' para o topo
	if (pred != NULL)
	{
		while (b != NULL && b->value != pred->value)
		{
			cost_b++;
			b = b->next;
		}
	}
	else
	{
		// Se não houver antecessor, mover o maior elemento em 'b' para o topo
		while (b != NULL)
		{
			cost_b++;
			b = b->next;
		}
	}
	return (cost_a + cost_b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	t_stack	*current;
        t_stack	*temp;
	int		len_stack;
	int		tr;
	int		fal;

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
			printf("Antecessor: %d\n", find_predecessor(*a,
					(*a)->value)->value);
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
			current = *a;
			tr = len_stack - (current->index + 1);
			fal = tr - len_stack / 2;
                        if (find_predecessor(*b, temp->value))
                        {
                                printf("Antecessor: %d\n", find_predecessor(*b,
					temp->value)->value);
                        }
                        else
                                printf("Sem antecessor\n");
			
			// ft_lstprint(*a);
                        temp = temp->next;
		}
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