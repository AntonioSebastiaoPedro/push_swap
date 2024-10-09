/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:24:20 by ansebast          #+#    #+#             */
/*   Updated: 2024/10/10 00:20:35 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**instructions(void)
{
	char	*line;
	char	**opers;
	int		len;

	len = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		free(line);
		len++;
	}
	opers = (char **)malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		opers[len] = ft_join_free_str(ft_strdup(""), line);
		free(line);
		len++;
	}
	return (opers);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	char	**opers;
	int		i;

	i = 0;
	opers = instructions();
	while (opers[i])
	{
		if (ft_strncmp("pa\n", opers[i], 3) == 0)
			pa(a, b);
		else if (ft_strncmp("pb\n", opers[i], 3) == 0)
			pb(a, b);
		else if (ft_strncmp("ra\n", opers[i], 3) == 0)
			ra(a);
		else if (ft_strncmp("rb\n", opers[i], 3) == 0)
			rb(b);
		else if (ft_strncmp("rra\n", opers[i], 4) == 0)
			rra(a);
		else if (ft_strncmp("rrb\n", opers[i], 4) == 0)
			rrb(b);
		else if (ft_strncmp("sa\n", opers[i], 3) == 0)
			sa(a);
		else if (ft_strncmp("sb\n", opers[i], 3) == 0)
			sb(b);
		else if (ft_strncmp("rr\n", opers[i], 3) == 0)
			rr(a, b);
		else if (ft_strncmp("rrr\n", opers[i], 4) == 0)
			rrr(a, b);
		else if (ft_strncmp("ss\n", opers[i], 3) == 0)
			ss(a, b);
		else
		{
			ft_lstclear(a);
			ft_lstclear(b);
			ft_puterror();
		}
		i++;
	}
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

void	add_to_stack(t_stack **a, int value)
{
	t_stack	*new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
		ft_puterror();
	ft_lstadd_back(a, new_node);
}
