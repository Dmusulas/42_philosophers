/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:10:30 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 03:10:30 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_main(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	set_last_eat_time(philo);
	if (philo->id % 2 == 0)
	{
		ft_usleep(philo->params->time_eat);
		print_msg(philo->params, philo->id, MSG_STATUS_THINK);
	}
	while (get_philo_state(philo) != DEAD)
	{
		if (_eat(philo))
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (_sleep(philo))
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (_think(philo))
			break ;
	}
	return (NULL);
}

void	*routine_check_full(void *params_p)
{
	t_params	*params;
	int			i;
	int			num_philos;

	params = (t_params *)params_p;
	num_philos = get_num_of_philos(params);
	i = 0;
	while (i < num_philos && get_run(params))
	{
		usleep(1000);
		if (!is_philo_full(&params->philos[i]))
			break ;
		i++;
	}
	if (get_run(params))
	{
		set_run(params, false);
		set_all_states(&params->philos[0], DEAD);
	}
	return (NULL);
}

void	*routine_check_dead(void *params_p)
{
	t_params	*params;
	t_philo		*philos;
	int			i;
	int			num_philos;

	params = (t_params *)params_p;
	philos = params->philos;
	num_philos = get_num_of_philos(params);
	i = 0;
	while (i < num_philos && get_run(params))
	{
		if (is_philo_dead(&philos[i]) && get_run(params))
		{
			print_msg(params, philos[i].id, MSG_STATUS_DIE);
			set_run(params, false);
			set_all_states(&params->philos[0], DEAD);
			break ;
		}
		usleep(1000);
		i++;
	}
	return (NULL);
}
