/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:28:43 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/23 07:05:22 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*current;

	if (*head)
	{
		current = ft_lstlast(*head);
		current->next = new_node;
		new_node->previous = current;
		new_node->index = current->index + 1;
		new_node->next = NULL;
	}
}
