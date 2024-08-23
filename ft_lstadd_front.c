/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:28:49 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/22 18:23:42 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack **head, t_stack *new_node)
{
	t_stack	*current;

	if (head && new_node)
	{
		(*head)->previous = new_node;
		current = new_node->next;
		while (current != NULL)
		{
			current->index++;
			current = current->next;
		}
		*head = new_node;
	}
}
