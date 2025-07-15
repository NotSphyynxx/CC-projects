/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:29:13 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/07/15 23:29:32 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void program_boot(t_program *prog, int num_philos)
{
	prog->dead_flag = 0;
	prog->num_philos = num_philos;
	if (pthread_mutex_init(&prog->dead_lock, NULL) != 0)
	{
        perror("Failed to init dead_lock mutex");
        exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&prog->meal_lock, NULL) != 0)
	{
        perror("Failed to init meal_lock mutex");
        exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&prog->write_lock, NULL) != 0)
	{
        perror("Failed to init write_lock mutex");
        exit(EXIT_FAILURE);
	}
}

void forks_boot(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			perror("Failed to init fork mutex");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
void philos_boot(t_philo *philos, pthread_mutex_t *forks, t_program *prog, char **av)
{
	int	num_philos;
	int	i;
	
	num_philos = ft_atoi(av[1]);
	i = 0;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = 0;
		philos[i].num_of_philos = num_philos;
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		fifth_arg_check(philos, i, av);
		philos[i].dead = &prog->dead_flag;
		philos[i].write_lock = &prog->write_lock;
		philos[i].dead_lock = &prog->dead_lock;
		philos[i].r_fork = &forks[(i + 1) % num_philos];
		philos[i].l_fork = &forks[i];
		i++; 
	}
}

void	threads_launch(t_philo *philos, int num_philos)
{
	int	i;
	size_t	start_time;

	start_time = get_current_time();
	i = 0;
	while (i < num_philos)
	{
		philos[i].start_time = start_time;
		philos[i].last_meal = start_time;
		pthread_create(&philos[i].thread, NULL, philo_routine, (void *)&philos[i]);
		i++;
	}
}
