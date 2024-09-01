/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:14:42 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/01 00:56:55 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			ft_freearray(args, ft_tablen(args));
			ft_puterror();
		}
		(*numbers)[*k] = ft_atoi(args[j]);
		(*k)++;
		j++;
	}
	ft_freearray(args, ft_tablen(args));
}

void	validate_arguments(int argc, char **argv, t_stack **a)
{
	int	*numbers;
	int	i;
	int	k;

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
