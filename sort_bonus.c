/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:24:20 by ansebast          #+#    #+#             */
/*   Updated: 2024/10/10 08:14:55 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_stack(t_stack **a, t_stack **b)
{
	if (ft_lstissorted(*a) && ft_lstsize(*b) == 0)
	{
		ft_lstclear(a);
		ft_lstclear(b);
		ft_putstr_fd("OK\n", 1);
	}
	else
	{
		ft_lstclear(a);
		ft_lstclear(b);
		ft_putstr_fd("KO\n", 1);
	}
}

void	free_stack(t_stack **a, t_stack **b, char **line)
{
	free(*line);
	ft_lstclear(a);
	ft_lstclear(b);
	ft_puterror();
}

void	apply_oper(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp("pa\n", line, 3) == 0)
		pa(a, b);
	else if (ft_strncmp("pb\n", line, 3) == 0)
		pb(a, b);
	else if (ft_strncmp("ra\n", line, 3) == 0)
		ra(a);
	else if (ft_strncmp("rb\n", line, 3) == 0)
		rb(b);
	else if (ft_strncmp("rra\n", line, 4) == 0)
		rra(a);
	else if (ft_strncmp("rrb\n", line, 4) == 0)
		rrb(b);
	else if (ft_strncmp("sa\n", line, 3) == 0)
		sa(a);
	else if (ft_strncmp("sb\n", line, 3) == 0)
		sb(b);
	else if (ft_strncmp("rr\n", line, 3) == 0)
		rr(a, b);
	else if (ft_strncmp("rrr\n", line, 4) == 0)
		rrr(a, b);
	else if (ft_strncmp("ss\n", line, 3) == 0)
		ss(a, b);
	else
		free_stack(a, b, &line);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		apply_oper(a, b, line);
		free(line);
	}
	check_stack(a, b);
}

void	add_to_stack(t_stack **a, int value)
{
	t_stack	*new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
		ft_puterror();
	ft_lstadd_back(a, new_node);
}
