/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:17:56 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/16 15:57:49 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void	radix_sort(t_list **stack_a)
{
	t_list *stack_b;
	int max;
	int digits;
	int exp;
	int i;
	int value;

	max = ft_lstget_max(*stack_a);
	digits = ft_count_digits(max);
	exp = 1;
	i = 0;
	while (i < digits)
	{
		stack_b = NULL;

		while (*stack_a)
		{
			value = *(int *)(*stack_a)->content;
			if ((value / exp) % 10 == 0)
				pb(stack_a, &stack_b);
			else
				ra(stack_a);
		}

		while (stack_b)
			pa(&stack_b, stack_a);

		exp *= 10;
		i++;
	}
}