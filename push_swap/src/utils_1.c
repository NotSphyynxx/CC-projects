/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:47:28 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/07 23:49:49 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	digit_check(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		close_error();
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		while (str[i] <= 32 && str[i])
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			close_error();
		i++;
	}
}

void	dup_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (!str[j])
			break ;
		if (ft_strcmp(str[i], str[j]) == 0)
			close_error();
		i++;
	}
}

void	close_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	handle_failure(char **str)
{
	if (!str || !(*str))
		close_error();
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
}
