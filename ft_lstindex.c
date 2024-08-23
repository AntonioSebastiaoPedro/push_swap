/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:00:55 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/23 14:13:27 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstindex(t_stack **head)
{
        t_stack *current;
        int     i;
        
        i = 0;
        current = *head;
        while (current)
        {
                current->index = i;
                i++;
                current = current->next;
        }
        
}