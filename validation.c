/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:14:42 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/29 10:18:45 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sorted(t_stack *stack)
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

int	has_duplicates(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}

int	is_integer(const char *str)
{
	char	*endptr;
	long	val;

	if (*str == '\0')
		return (0);
	val = strtol(str, &endptr, 10);
	if (*endptr != '\0' || val < -2147483648 || val > 2147483647)
		return (0);
	return (1);
}

// int	validate_arguments(int argc, char **argv)
// {
// 	if (argc < 2)
// 	{
// 		return (0);
// 	}

// 	int *numbers = malloc((argc - 1) * sizeof(int));
// 	if (!numbers)
// 	{
// 		return (0);
// 	}

// 	for (int i = 1; i < argc; i++)
// 	{
// 		if (!is_integer(argv[i]))
// 		{
// 			free(numbers);
// 			return (0);
// 		}
// 		numbers[i - 1] = atoi(argv[i]);
// 	}if (is_sorted(numbers, argc - 1) || argc == 2)
// 	// {
// 	// 	free(numbers);
// 	// 	return (-1);
// 	// }

// 	if (has_duplicates(numbers, argc - 1))
// 	{
// 		free(numbers);
// 		return (0);
// 	}

// 	// if (is_sorted(numbers, argc - 1) || argc == 2)
// 	// {
// 	// 	free(numbers);
// 	// 	return (-1);
// 	// }
// 	free(numbers);
// 	return (1);
// }