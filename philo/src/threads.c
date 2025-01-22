/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:10:16 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 03:10:16 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Creates and runs threads for the philosopher simulation.
 *
 * Initializes threads for each philosopher and monitoring routines.
 * Ensures proper synchronization and thread creation.
 *
 * @param params Pointer to the `t_params` structure containing simulation
 * parameters.
 * @return 0 on success, 1 on failure.
 */
int	run_threads(t_params *params)
{
	int	i;
	int	num_of_philos;

	num_of_philos = get_num_of_philos(params);
	i = 0;
	params->time_start = get_time();
	while (++i < num_of_philos)
	{
		if (pthread_create(&params->philo_threads[i], NULL, &routine,
				&params->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&params->monit_all_alive, NULL, &all_alive_routine,
			params))
		return (1);
	if (params->num_times_to_eat > 0 && pthread_create(&params->monit_all_full,
			NULL, &all_full_routine, params))
		return (1);
	return (0);
}

/**
 * @brief Joins threads after the simulation ends.
 *
 * Waits for all philosopher threads and monitoring routines to complete
 * execution.
 *
 * @param params Pointer to the `t_params` structure containing simulation
 * parameters.
 * @return 0 on success, 1 on failure.
 */
int	join_threads(t_params *params)
{
	int	i;
	int	num_of_philos;

	num_of_philos = get_num_of_philos(params);
	i = 0;
	if (pthread_join(params->monit_all_alive, NULL))
		return (1);
	if (params->num_times_to_eat > 0 && pthread_join(params->monit_all_full,
			NULL))
		return (1);
	while (++i < num_of_philos)
	{
		if (pthread_join(params->philo_threads[i], NULL))
			return (1);
	}
	return (0);
}
