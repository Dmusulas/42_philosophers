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

static int	handle_one_philo(t_philo *philo)
{
	take_fork(philo, LEFT);
	ft_usleep(get_time_die(philo->params));
	set_philo_state(philo, DEAD);
	return (1);
}

int	take_forks(t_philo *philo)
{
	if (get_num_of_philos(philo->params) == 1)
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

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
