/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:16:48 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/24 20:45:13 by ansebast         ###   ########.fr       */
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

int	calc_cost(t_stack **a, t_stack *current)
{
	int	cost;
        int     index;
        int     size;

        index = ft_lstgetindex(a, current);
        size = ft_lstsize(*a);
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

int	check_mov(t_stack **a, t_stack *value)
{
	int	local;
        int     index;
        int     size;

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
                        t_stack *preces = find_predecessor(*b, temp->value);
			if (preces)
			{
				printf("Antecessor: %d\n", preces->value);
                                printf ("Local A: %d\n", check_mov(a, temp));
                                printf ("Custo A: %d\n", calc_cost(a, temp));
                                printf ("Local B: %d\n", check_mov(b, preces));
                                printf ("Custo B: %d\n", calc_cost(b, preces));
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