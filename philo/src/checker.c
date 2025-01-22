/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:30:50 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 17:47:36 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Checks if a philosopher is dead based on the current time,
 * last time they ate, and their time to die.
 *
 * @param philo Pointer to the philosopher structure.
 * @return true if the philosopher is dead, false otherwise.
 */
bool	is_philo_dead(t_philo *philo)
{
	time_t	current_time;
	time_t	last_eat_time;
	time_t	time_to_die;

	current_time = get_time();
	last_eat_time = get_last_eat_time(philo);
	time_to_die = get_time_die(philo->params);
	if ((current_time - last_eat_time > time_to_die)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		return (true);
	}
	return (false);
}

/**
 * Checks if a philosopher has eaten enough times to be considered full.
 *
 * @param philo Pointer to the philosopher structure.
 * @return true if the philosopher is full, false otherwise.
 */
bool	is_philo_full(t_philo *philo)
{
	return (philo->params->num_times_to_eat != -1
		&& get_meals_eaten(philo) >= philo->params->num_times_to_eat);
}
