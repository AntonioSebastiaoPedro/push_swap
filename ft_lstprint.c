/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:09:06 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 11:12:03 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstprint(t_stack *head)
{
        while (head)
        {
                printf("%d - Indice[%d]\n", head->value, head->index);
                head = head->next;
        }
        
}