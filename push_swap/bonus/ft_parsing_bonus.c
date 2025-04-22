/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:45:36 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/06 16:45:41 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	ft_valid_args(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = 0;
		if (ft_is_signed(v[i][j]))
			j++;
		while (v[i][j])
		{
			if (!ft_is_digit(v[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_is_duplicated(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			if (ft_atoi(v[i]) == ft_atoi(v[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parsing(char **v)
{
	if (!v)
	{
		free_arr(v);
		ft_error();
		exit(1);
	}
	if (!ft_valid_args(v))
	{
		free_arr(v);
		ft_error();
		exit(1);
	}
	if (!ft_is_duplicated(v))
	{
		free_arr(v);
		ft_error();
		exit(1);
	}
}
