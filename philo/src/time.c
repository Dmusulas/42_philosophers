/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:02:55 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 00:02:55 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Retrieves the current time in milliseconds.
 *
 * Utilizes the `gettimeofday` function to calculate the current time
 * relative to the epoch in milliseconds.
 *
 * @return The current time in milliseconds, or 0 on failure.
 */
time_t	get_mtime(void)
{
	struct timeval	tv_now;

	if (gettimeofday(&tv_now, NULL))
		return (1);
	return ((tv_now.tv_sec * 1000) + (tv_now.tv_usec / 1000));
}

/**
 * @brief Sleeps for the specified duration in milliseconds.
 *
 * Implements a sleep function with precision by checking the elapsed
 * time and sleeping for small intervals.
 *
 * @param time_to_sleep Duration to sleep in milliseconds.
 */
void	ft_usleep(time_t time_to_sleep)
{
	time_t	start_time;

	start_time = get_mtime();
	while ((get_mtime() - start_time) < time_to_sleep)
		usleep(200);
}

/**
 * @brief Helper function for locking mutex and getting value from a struct.
 */
time_t	get_time_param(pthread_mutex_t *mutex, time_t *field)
{
	time_t	value;

	pthread_mutex_lock(mutex);
	value = *field;
	pthread_mutex_unlock(mutex);
	return (value);
}
