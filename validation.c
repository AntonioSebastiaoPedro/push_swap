/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:14:42 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/30 17:30:22 by ansebast         ###   ########.fr       */
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

int	validate_arguments(int argc, char **argv)
{
	int *numbers;
	int i;

	numbers = ft_calloc((argc - 1), sizeof(int));
	i = 1;
	if (!numbers)
		return (0);

	while (i < argc)
	{
		if (!ft_isint(argv[i]))
		{
			free(numbers);
			ft_puterror();
		}
		numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (has_duplicates(numbers, argc - 1))
	{
		free(numbers);
		ft_puterror();
	}
	if (ft_issorted(numbers, argc - 1))
	{
		free(numbers);
		exit(0);
	}
	free(numbers);
	return (1);
}