/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:44:26 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/22 18:31:52 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pushswap.h"
#include <stdio.h>
#include <stdlib.h>

// Funções de manipulação de pilha (sa, sb, pa, pb, ra, rra, etc.) aqui...

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	t_stack	*current;

	while (*a != NULL)
	{
		// Encontra o menor elemento na pilha a
		min_node = *a;
		current = *a;
		while (current != NULL)
		{
			if (current->value < min_node->value)
			{
				min_node = current;
			}
			current = current->next;
		}
		// Mover o menor elemento para a pilha b
		while (*a != min_node)
		{
			// Se o menor elemento não estiver no topo, rotaciona
			ra(a);
			printf("ra\n");
		}
		// Agora o menor elemento está no topo, move para b
		pb(a, b);
		printf("pb\n");
	}
	// Agora, movemos os elementos de b de volta para a
	while (*b != NULL)
	{
		pa(a, b);
		printf("pa\n");
	}
}

// Função para adicionar números à pilha a
void	add_to_stack(t_stack **a, int value)
{
	t_stack	*new_node;
	t_stack	*current;
	int		index;

	new_node = ft_lstnew(value);
	if (new_node == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	new_node->next = *a;
	(*a)->previous = new_node;
	*a = new_node;
	// Atualiza os índices
	current = *a;
	index = 0;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return (0); // Não faz nada se não houver argumentos
	}

	t_stack *a = NULL;
	t_stack *b = NULL;

	for (int i = 1; i < argc; i++)
	{
		add_to_stack(&a, atoi(argv[i]));
	}

	sort_stack(&a, &b);
	return (0);
}