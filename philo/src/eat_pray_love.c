/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_pray_love.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:14:19 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/27 05:59:32 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Makes a philosopher perform the eating action.
 *
 * This function sets the philosopher's state to eating, updates the last
 * meal time, increments the meal counter, and holds forks for the
 * duration of the eating period.
 *
 * @param philo Pointer to the philosopher structure.
 * @return 0 on success, 1 if an error occurs.
 */
int	_eat(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	if (params->num_times_to_eat != -1
		&& get_meals_eaten(philo) >= params->num_times_to_eat)
		return (1);
	if (take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	print_msg(params, philo->id, MSG_STATUS_EAT);
	set_last_eat_time(philo);
	ft_usleep(get_time_eat(params));
	set_meals_eaten(philo);
	drop_forks(philo);
	return (0);
}

/**
 * @brief Makes a philosopher perform the sleeping action.
 *
 * Sets the philosopher's state to sleeping and waits for the specified
 * sleep duration unless the philosopher is dead.
 *
 * @param philo Pointer to the philosopher structure.
 * @return 0 on success, 1 if the philosopher is dead.
 */
int	_sleep(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	set_philo_state(philo, SLEEPING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(params, philo->id, MSG_STATUS_SLEEP);
	ft_usleep(get_time_sleep(params));
	return (0);
}

/**
 * @brief Makes a philosopher perform the thinking action.
 *
 * Sets the philosopher's state to thinking and waits for the specified
 * sleep duration unless the philosopher is dead.
 *
 * @param philo Pointer to the philosopher structure.
 * @return 0 on success, 1 if the philosopher is dead.
 */
int	_think(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(params, philo->id, MSG_STATUS_THINK);
	return (0);
}
