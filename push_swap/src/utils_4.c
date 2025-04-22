/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:42:30 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:23:45 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	jump(const char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	return (*i);
}

static int	check_sg(const char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (*i);
}

long	ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	jump(str, &i);
	check_sg(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 922337203685477580
			|| (result == 922337203685477580 && (str[i] - '0') > 7))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((result * sign));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	handle_node(t_stack *new_node)
{
	if (!new_node)
		close_error();
}
