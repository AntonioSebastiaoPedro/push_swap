/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:22 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/27 14:11:46 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_stack *head)
{
	t_stack *current;
	current = head;
	while (current)
	{
		printf("%d - Indice [%d]\n", current->value, current->index);
		current = current->next;
	}
	printf("\n");
}