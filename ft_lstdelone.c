/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:29:01 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/22 16:54:01 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_stack *node)
{
	if (node)
		return ;
	if (node->previous != NULL)
		node->previous->next = node->next;
	if (node->next != NULL)
		node->next->previous = node->previous;
	free(node);
}
