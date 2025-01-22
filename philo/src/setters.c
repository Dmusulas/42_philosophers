/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:45:34 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 02:45:34 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Sets the run state of the program.
 *
 * Updates the `run` field in the `params` structure while ensuring
 * thread safety using a mutex.
 *
 * @param params Pointer to the `t_params` structure.
 * @param set_to The boolean value to set the `run` state to.
 */
void	set_run(t_params *params, bool set_to)
{
	pthread_mutex_lock(&params->mut_run);
	params->run = set_to;
	pthread_mutex_unlock(&params->mut_run);
}

/**
 * @brief Updates the state of a philosopher.
 *
 * Changes the state of a philosopher, provided it is not already `DEAD`.
 * Ensures thread safety with a mutex.
 *
 * @param philo Pointer to the `t_philo` structure.
 * @param state The new state to assign to the philosopher.
 */
void	set_philo_state(t_philo *philo, t_philo_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

void	set_all_states(t_philo *philo, t_philo_state state)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	nb_philos = get_num_of_philos(philo->params);
	philos = philo->params->philos;
	i = 0;
	while (i < nb_philos)
	{
		set_philo_state(&philos[i], state);
		i++;
	}
}

void	set_last_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_eat_time);
	philo->last_eat_time = get_mtime();
	pthread_mutex_unlock(&philo->mut_last_eat_time);
}

void	set_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_meals_eaten);
	philo->meals_eaten = philo->meals_eaten + 1;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
}
