/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_pray_love.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:14:19 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 12:14:19 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_eat(t_philo *philo)
{
	t_params	*params;

	params = philo->params;
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
