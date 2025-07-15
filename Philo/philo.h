/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:47:12 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/07/15 23:34:35 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define MAX_PHILOS 200
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];
	int				num_philos;
}	t_program;

//------------Parsing-------------//
int			philo_parse(int ac, char **av);
void		program_boot(t_program *prog, int num_philos);
void		forks_boot(pthread_mutex_t *forks, int num);
void		philos_boot(t_philo *philos, pthread_mutex_t *forks, t_program *prog, char **av);
void		threads_launch(t_philo *philos, int num);
void		threads_joining(t_philo *philos, int num);
void		destroy_mutexes(t_program *prog, pthread_mutex_t *forks, int num);

//-----------Utils----------------//
int			is_numeric(const char *str);
int			ft_atoi(const char *str);
size_t		get_current_time(void);
void		*philo_routine(void *arg);
void		fifth_arg_check(t_philo *philos, int i, char **av);

#endif