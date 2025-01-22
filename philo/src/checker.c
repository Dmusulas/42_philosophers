/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:30:50 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 15:30:50 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_philo_dead(t_philo *philo)
{
	if (get_time() - get_last_eat_time(philo) > get_time_die(philo->params)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		return (true);
	}
	return (false);
}

bool	is_philo_full(t_philo *philo)
{
	if (get_meals_eaten(philo) >= philo->params->num_times_to_eat)
		return (true);
	return (false);
}
