/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:26:04 by dmusulas          #+#    #+#             */
/*   Updated: 2024/12/09 18:26:04 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initializes mutexes for forks and assigns them to philosophers.
 *
 * Sets up mutex locks for forks and assigns the appropriate forks to each
 * philosopher based on their position in the array.
 *
 * @param params Pointer to the `t_params` structure containing simulation
 * data.
 * @return Always returns 0.
 */
static int	init_forks(t_params *params)
{
	int		i;
	t_philo	*philos;

	philos = params->philos;
	i = 0;
	while (i < params->num_of_philos)
	{
		pthread_mutex_init(&params->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < params->num_of_philos)
	{
		philos[i].l_fork = &params->forks[i];
		if (i == 0)
			philos[i].r_fork = &params->forks[params->num_of_philos - 1];
		else
			philos[i].r_fork = &params->forks[i - 1];
		i++;
	}
	return (0);
}

/**
 * @brief Initializes all philosophers for the simulation.
 *
 * Sets initial values for each philosopher, including their ID, state, and
 * meal count. Also initializes all philosopher-specific mutexes.
 *
 * @param params Pointer to the `t_params` structure containing simulation
 * data.
 * @return Always returns 0.
 */
static int	init_philos(t_params *params)
{
	int		i;
	t_philo	*philos;

	philos = params->philos;
	i = 0;
	while (i < params->num_of_philos)
	{
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_meals_eaten, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		philos[i].params = params;
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].state = IDLE;
		set_last_eat_time(&philos[i]);
		i++;
	}
	return (0);
}

/**
 * @brief Allocates memory for simulation parameters.
 *
 * Dynamically allocates memory for the philosophers, forks, and threads
 * required for the simulation.
 *
 * @param data Pointer to the `t_params` structure to hold allocated memory.
 * @return 0 if successful, 1 if memory allocation fails.
 */
static int	malloc_params(t_params *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks)
		return (free(data->philos), 1);
	data->philo_threads = malloc(sizeof(pthread_t) * data->num_of_philos);
	if (!data->philo_threads)
		return (free(data->philos), free(data->forks), 1);
	return (0);
}

/**
 * @brief Initializes simulation parameters and allocates resources.
 *
 * Sets default values for the parameters, initializes mutex locks, and
 * allocates memory for simulation resources.
 *
 * @param params Pointer to the `t_params` structure.
 * @param argc The argument count from the command line.
 * @param argv The argument values from the command line.
 * @return 0 if successful, 1 if an error occurs.
 */
static int	init_params(t_params *params, int argc, char **argv)
{
	params->run = true;
	params->num_of_full_philos = 0;
	params->num_of_philos = ft_atoi(argv[1]);
	params->time_die = (time_t)ft_atoi(argv[2]);
	params->time_eat = (time_t)ft_atoi(argv[3]);
	params->time_sleep = (time_t)ft_atoi(argv[4]);
	if (argc == 6)
		params->num_times_to_eat = ft_atoi(argv[5]);
	else
		params->num_times_to_eat = -1;
	pthread_mutex_init(&params->mut_time_eat, NULL);
	pthread_mutex_init(&params->mut_time_sleep, NULL);
	pthread_mutex_init(&params->mut_time_die, NULL);
	pthread_mutex_init(&params->mut_print, NULL);
	pthread_mutex_init(&params->mut_num_of_philos, NULL);
	pthread_mutex_init(&params->mut_run, NULL);
	pthread_mutex_init(&params->mut_time_start, NULL);
	return (malloc_params(params));
}

/**
 * @brief Initializes the program and all its components.
 *
 * Sets up parameters, philosophers, and forks for the simulation.
 *
 * @param params Pointer to the `t_params` structure.
 * @param argc The argument count from the command line.
 * @param argv The argument values from the command line.
 * @return 0 if successful, 1 if an error occurs.
 */
int	init_program(t_params *params, int argc, char **argv)
{
	if (init_params(params, argc, argv))
		return (1);
	init_philos(params);
	init_forks(params);
	return (0);
}
