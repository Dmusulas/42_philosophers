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
u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

/**
 * @brief Sleeps for the specified duration in milliseconds.
 *
 * Implements a sleep function with precision by checking the elapsed
 * time and sleeping for small intervals.
 *
 * @param time_to_sleep Duration to sleep in milliseconds.
 */
void	ft_usleep(u_int64_t time_to_sleep)
{
	u_int64_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_to_sleep)
		usleep(200);
}
