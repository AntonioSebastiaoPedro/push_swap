/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:14:42 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/31 18:43:08 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstissorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	ft_issorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int     ft_lentab(char **tab)
{
        int     i;

        i = 0;
        while (tab[i])
                i++;
        return (i);
}

int	ft_isint(char *str)
{
	char	*endptr;
	long	val;

	if (*str == '\0' || (*str == '-' && *(str + 1) == '\0') || (*str == '+'
			&& *(str + 1) == '\0'))
		return (0);
	val = ft_strtol(str, &endptr);
	if (*endptr != '\0' || val < -2147483648 || val > 2147483647)
		return (0);
	return (1);
}

int     ft_isempty(char *str)
{
        int     i;

        i = 0;
        while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
                i++;
        return (str[i] == '\0');
}

void	validate_arguments(int argc, char **argv, t_stack**a)
{
	int *numbers;
	int i;
        int j;
        int     k;
        
        char **args;

        i = 1;
        k = 0;
	// numbers = ft_calloc((argc - 1), sizeof(int));
        numbers = ft_calloc(10000, sizeof(int));
	if (!numbers)
		return ;
	while (i < argc)
	{
                
                if (ft_isempty(argv[i]))
                {
                        free(numbers);
                        free(args);
                        ft_puterror();
                }
                args = ft_split(argv[i], ' ');
                
                j = 0;
                while (args[j])
                {
                        if (!ft_isint(args[j]))
                        {
                                free(numbers);
                                free(args);
                                ft_puterror();
                        }
                        numbers[k] = ft_atoi(args[j]);
                        k++;
                        j++;                      
                }
		i++;
	}
        if (k == 0 && argc > 1)
        {
                free(numbers);
                free(args);
                ft_puterror(); 
        }
	if (has_duplicates(numbers, k))
	{
		free(numbers);
                free(args);
		ft_puterror();
	}
	if (ft_issorted(numbers, k))
	{
		free(numbers);
                free(args);
		exit(0);
	}
        k--;
        i = 0;
        while (i <= k)
        {
                add_to_stack(a, numbers[i]);
                i++;
        }
        free(args);
	free(numbers);
}