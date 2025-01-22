/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:45:29 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 02:45:29 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Retrieves the current running state of the simulation.
 *
 * This function acquires a mutex lock to safely access the `run` flag in
 * the `params` structure, ensuring thread-safe operations.
 *
 * @param params Pointer to the `t_params` structure containing the `run` flag.
 * @return `true` if the simulation is running, `false` otherwise.
 */
bool	get_run(t_params *params)
{
	bool	current_state;

	pthread_mutex_lock(&params->mut_run);
	current_state = params->run;
	pthread_mutex_unlock(&params->mut_run);
	return (current_state);
}

/**
 * @brief Retrieves the number of philosophers in the simulation.
 *
 * This function acquires a mutex lock to safely access the `num_of_philos`
 * field in the `params` structure, ensuring thread-safe operations.
 *
 * @param params Pointer to the `t_params` structure containing the
 * philosopher count.
 * @return The number of philosophers.
 */
int	get_num_of_philos(t_params *params)
{
	int	philosopher_count;

	pthread_mutex_lock(&params->mut_num_of_philos);
	philosopher_count = params->num_of_philos;
	pthread_mutex_unlock(&params->mut_num_of_philos);
	return (philosopher_count);
}

/**
 * @brief Retrieves the current state of a philosopher.
 *
 * This function acquires a mutex lock to safely access the `state` field in
 * the `philo` structure, ensuring thread-safe operations.
 *
 * @param philo Pointer to the `t_philo` structure representing a philosopher.
 * @return The current state of the philosopher as a `t_philo_state`.
 */
t_philo_state	get_philo_state(t_philo *philo)
{
	t_philo_state	current_state;

	pthread_mutex_lock(&philo->mut_state);
	current_state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (current_state);
}

/**
 * @brief Retrieves the number of meals eaten by a philosopher.
 *
 * This function acquires a mutex lock to safely access the `meals_eaten`
 * field in the `philo` structure, ensuring thread-safe operations.
 *
 * @param philo Pointer to the `t_philo` structure representing a philosopher.
 * @return The number of meals eaten by the philosopher.
 */
int	get_meals_eaten(t_philo *philo)
{
	int	meals_count;

	pthread_mutex_lock(&philo->mut_meals_eaten);
	meals_count = philo->meals_eaten;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
	return (meals_count);
}
