/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:44:26 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/16 16:03:07 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// Funções de manipulação de pilhas (definidas anteriormente)
void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);

// Funções para Radix Sort (definidas anteriormente)
void radix_sort(t_list **stack_a);

// Função para adicionar um nó à pilha
void push(t_list **stack, int value)
{
    t_list *new_node = ft_lstnew((char *)value);
    if (new_node)
    {
        new_node->next = *stack;
        *stack = new_node;
    }
}

// Função para processar os argumentos
void process_arguments(int argc, char **argv, t_list **stack_a)
{
    for (int i = 1; i < argc; i++)
    {
        int value = atoi(argv[i]);
        push(stack_a, value);
    }
}

// Função principal
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        return 0; // Se não houver argumentos, sai sem fazer nada
    }

    t_list *stack_a = NULL;

    // Processar argumentos e criar a pilha A
    process_arguments(argc, argv, &stack_a);

    // Aplicar o Radix Sort
    radix_sort(&stack_a);

    // Aqui você pode imprimir as instruções geradas
    // Para simplificação, apenas mostraremos que a ordenação foi feita
    printf("Ordenação concluída!\n");

    // Liberar memória e limpar pilha (não mostrado)
    return 0;
}