/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:10:04 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/07/14 23:37:47 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_parse(int ac, char **av)
{
	int	i;
	int	value;

	i = 1;
	value = 0;
	if (ac != 5 && ac != 6)
	{
		printf("Error: wrong number of arguments.\n");
		return (1);
	}
	while (i < ac)
	{
		if (!is_numeric(av[i]))
			return (1);
		value = ft_atoi(av[i]);
		if (i == 1 && value > 200)
			return (1);
		if (i == 5 && value < 0)
			return (1);
		if (i != 5 && value <= 0)
			return (1);
		i++;
	}
	return (0);
}
