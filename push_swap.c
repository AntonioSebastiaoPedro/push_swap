/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:44:26 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/27 13:49:52 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
        t_stack *a = NULL;
	t_stack *b = NULL;
        int     i;
        
        i = 1;
	if (argc < 2)
	{
		return (0);
	}

	while (i < argc)
	{
		add_to_stack(&a, atoi(argv[i]));
                i++;
	}
        printf("Antes A:\n");
        ft_lstprint(a);
        sort_stack(&a, &b);
        printf("\nDepois:\n");
        ft_lstprint(a);
        printf("\n=========Verificao: %d============\n", is_sorted(a));

        return (0);
}