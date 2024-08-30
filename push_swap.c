/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:44:26 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/30 16:54:29 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int i;

	a = NULL;
	b = NULL;
	i = 1;
        validate_arguments(argc, argv);
	while (i < argc)
	{
		add_to_stack(&a, argv[i]);
		i++;
	}
	sort_stack(&a, &b);
	return (0);
}