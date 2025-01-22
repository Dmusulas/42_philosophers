/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:31:53 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 16:31:53 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Frees all allocated resources and destroys mutexes.
 *
 * Iterates through all philosophers and forks to destroy their mutexes,
 * then frees the allocated memory for threads, philosophers, and forks.
 *
 * @param params Pointer to the simulation parameters structure.
 */
void	free_params(t_params *params)
{
	int	i;
	int	num_of_philos;

	num_of_philos = get_num_of_philos(params);
	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_destroy(&params->forks[i]);
		pthread_mutex_destroy(&params->philos[i].mut_state);
		pthread_mutex_destroy(&params->philos[i].mut_meals_eaten);
		pthread_mutex_destroy(&params->philos[i].mut_last_eat_time);
		i++;
	}
	pthread_mutex_destroy(&params->mut_time_start);
	pthread_mutex_destroy(&params->mut_time_eat);
	pthread_mutex_destroy(&params->mut_time_die);
	pthread_mutex_destroy(&params->mut_time_sleep);
	pthread_mutex_destroy(&params->mut_num_of_philos);
	pthread_mutex_destroy(&params->mut_print);
	pthread_mutex_destroy(&params->mut_run);
	free(params->philo_threads);
	free(params->philos);
	free(params->forks);
}
