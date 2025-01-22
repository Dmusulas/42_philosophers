/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:57:49 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 02:57:49 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Retrieves the time to die parameter.
 *
 * Acquires a mutex lock to safely access the `time_die` field in the
 * `params` structure, ensuring thread-safe operations.
 *
 * @param params Pointer to the `t_params` structure containing the time
 * to die.
 * @return The time to die in milliseconds.
 */
uint64_t	get_time_die(t_params *params)
{
	uint64_t	death_time;

	pthread_mutex_lock(&params->mut_time_die);
	death_time = params->time_die;
	pthread_mutex_unlock(&params->mut_time_die);
	return (death_time);
}

/**
 * @brief Retrieves the time to sleep parameter.
 *
 * Acquires a mutex lock to safely access the `time_sleep` field in the
 * `params` structure, ensuring thread-safe operations.
 *
 * @param params Pointer to the `t_params` structure containing the time
 * to sleep.
 * @return The time to sleep in milliseconds.
 */
uint64_t	get_time_sleep(t_params *params)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&params->mut_time_sleep);
	sleep_time = params->time_sleep;
	pthread_mutex_unlock(&params->mut_time_sleep);
	return (sleep_time);
}

/**
 * @brief Retrieves the time to eat parameter.
 *
 * Acquires a mutex lock to safely access the `time_eat` field in the
 * `params` structure, ensuring thread-safe operations.
 *
 * @param params Pointer to the `t_params` structure containing the time
 * to eat.
 * @return The time to eat in milliseconds.
 */
uint64_t	get_time_eat(t_params *params)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&params->mut_time_eat);
	eat_time = params->time_eat;
	pthread_mutex_unlock(&params->mut_time_eat);
	return (eat_time);
}

/**
 * @brief Retrieves the last meal time of a philosopher.
 *
 * Acquires a mutex lock to safely access the `last_eat_time` field in the
 * `philo` structure, ensuring thread-safe operations.
 *
 * @param philo Pointer to the `t_philo` structure representing a
 * philosopher.
 * @return The last meal time of the philosopher in milliseconds.
 */
uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t	meal_time;

	pthread_mutex_lock(&philo->mut_last_eat_time);
	meal_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (meal_time);
}

/**
 * @brief Retrieves the start time of the simulation.
 *
 * Acquires a mutex lock to safely access the `time_start` field in the
 * `params` structure, ensuring thread-safe operations.
 *
 * @param params Pointer to the `t_params` structure containing the start
 * time.
* @return The simulation start time in milliseconds.
 */
uint64_t	get_time_start(t_params *params)
{
	uint64_t	start_time;

	pthread_mutex_lock(&params->mut_time_start);
	start_time = params->time_start;
	pthread_mutex_unlock(&params->mut_time_start);
	return (start_time);
}
