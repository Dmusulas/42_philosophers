/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:16:53 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 12:16:53 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Makes a philosopher take a specific fork.
 *
 * Locks the mutex for the specified fork and logs the action.
 *
 * @param philo Pointer to the philosopher structure.
 * @param fork Fork type (LEFT or RIGHT).
 * @return 0 on success, 1 if an error occurs.
 */
static int	take_fork(t_philo *philo, t_fork fork)
{
	if (is_philo_dead(philo))
		return (1);
	if (fork == RIGHT)
		pthread_mutex_lock(philo->r_fork);
	else if (fork == LEFT)
		pthread_mutex_lock(philo->l_fork);
	else
		return (1);
	print_msg(philo->params, philo->id, MSG_STATUS_TAKE);
	return (0);
}

/**
 * @brief Handles a single philosopher case.
 *
 * The philosopher takes a single fork, waits for the time to die,
 * and is then marked as dead.
 *
 * @param philo Pointer to the philosopher structure.
 * @return Always returns 1.
 */
static int	handle_one_philo(t_philo *philo)
{
	take_fork(philo, LEFT);
	ft_usleep(get_time_die(philo->params));
	set_philo_state(philo, DEAD);
	return (1);
}

/**
 * @brief Makes a philosopher take both forks.
 *
 * Handles the logic for acquiring left and right forks. If the philosopher
 * has only one fork available, they are marked as dead.
 *
 * @param philo Pointer to the philosopher structure.
 * @return 0 on success, 1 if an error occurs.
 */
int	take_forks(t_philo *philo)
{
	if (philo->r_fork == philo->l_fork)
		return (handle_one_philo(philo));
	if (take_fork(philo, RIGHT))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	if (take_fork(philo, LEFT))
	{
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	return (0);
}

/**
 * @brief Releases the forks held by a philosopher.
 *
 * Unlocks the mutexes for both the left and right forks.
 *
 * @param philo Pointer to the philosopher structure.
 */
void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
