/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:44:26 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/30 07:23:46 by ansebast         ###   ########.fr       */
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
	if (argc < 2)
	{
		return (0);
	}
        // if (argv[1] == "")
        // {
        //         write(1, "Error\n", 6);
        // }
        
	while (i < argc)
	{
		add_to_stack(&a, argv[i]);
		i++;
	}
	sort_stack(&a, &b);
        // ft_lstprint(a);
	return (0);
}