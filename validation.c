/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:14:42 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/31 20:34:12 by ansebast         ###   ########.fr       */
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

int	ft_lentab(char **tab)
{
	int	i;

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

int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (str[i] == '\0');
}

void	validate_error(int *k, int *argc, int **numbers)
{
	if (*k == 0 && *argc > 1)
	{
		free(*numbers);
		ft_puterror();
	}
	if (has_duplicates(*numbers, *k))
	{
		free(*numbers);
		ft_puterror();
	}
	if (ft_issorted(*numbers, *k))
	{
		free(*numbers);
		exit(0);
	}
}

void	fill_stack(int k, int *numbers, t_stack **a)
{
	int	i;

	k--;
	i = 0;
	while (i <= k)
	{
		add_to_stack(a, numbers[i]);
		i++;
	}
}

void	fill_number(char **argv, int *k, int **numbers)
{
	int		j;
	char	**args;

	args = ft_split(*argv, ' ');
	j = 0;
	while (args[j])
	{
		if (!ft_isint(args[j]))
		{
			free(*numbers);
			ft_freearray(args, ft_lentab(args));
			ft_puterror();
		}
		(*numbers)[*k] = ft_atoi(args[j]);
		(*k)++;
		j++;
	}
	ft_freearray(args, ft_lentab(args));
}

void	validate_arguments(int argc, char **argv, t_stack **a)
{
	int *numbers;
	int i;
	int k;

	i = 1;
	k = 0;
	numbers = ft_calloc(10000, sizeof(int));
	if (!numbers)
		ft_puterror();
	while (i < argc)
	{
		if (ft_isempty(argv[i]))
		{
			free(numbers);
			ft_puterror();
		}
		fill_number(&argv[i], &k, &numbers);
		i++;
	}
	validate_error(&k, &argc, &numbers);
	fill_stack(k, numbers, a);
	free(numbers);
}