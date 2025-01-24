/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:16:53 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/24 17:56:55 by dmusulas         ###   ########.fr       */
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
static int	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	if (is_philo_dead(philo))
		return (1);
	pthread_mutex_lock(fork);
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
	take_fork(philo->l_fork, philo);
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
	if (philo->l_fork < philo->r_fork)
	{
		if (take_fork(philo->l_fork, philo))
			return (1);
		if (take_fork(philo->r_fork, philo))
		{
			pthread_mutex_unlock(philo->l_fork);
			return (1);
		}
	}
	else if (philo->l_fork > philo->r_fork)
	{
		if (take_fork(philo->r_fork, philo))
			return (1);
		if (take_fork(philo->l_fork, philo))
		{
			pthread_mutex_unlock(philo->r_fork);
			return (1);
		}
	}
	else
		return (handle_one_philo(philo));
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
	if (philo->l_fork != philo->r_fork)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
		pthread_mutex_unlock(philo->l_fork);
}
