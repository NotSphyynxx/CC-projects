/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:48:45 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/07/15 23:32:19 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_program		prog;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];

	if (philo_parse(ac, av))
	{
		printf("Error: argument invalid!\n");
		return (1);
	}
	program_boot(&prog, ft_atoi(av[1]));
	forks_boot(forks, ft_atoi(av[1]));
	philos_boot(philos, forks, &prog, av);
	threads_launch(philos, ft_atoi(av[1]));
	//threads_joining(philos, ft_atoi(av[1]));
	//destroy_mutexes(&prog, forks, ft_atoi(av[1]));
	sleep(1);
	return (0);
}
