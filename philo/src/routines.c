/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 03:10:30 by dmusulas          #+#    #+#             */
/*   Updated: 2025/01/22 17:47:24 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_main(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	set_last_eat_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->params->time_eat);
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
	int			full_count;

	params = (t_params *)params_p;
	while (get_run(params))
	{
		i = -1;
		full_count = 0;
		while (++i < get_num_of_philos(params))
			if (is_philo_full(&params->philos[i]))
				full_count++;
		if (full_count == get_num_of_philos(params))
		{
			set_run(params, false);
			set_all_states(&params->philos[0], DEAD);
			break ;
		}
		usleep(SLEEP_BUFFER);
	}
	return (NULL);
}

void	*routine_check_dead(void *params_p)
{
	t_params	*params;
	t_philo		*philos;
	int			i;

	params = (t_params *)params_p;
	philos = params->philos;
	while (get_run(params))
	{
		i = 0;
		while (i < get_num_of_philos(params) && get_run(params))
		{
			if (is_philo_dead(&philos[i]))
			{
				print_msg(params, philos[i].id, MSG_STATUS_DIE);
				set_run(params, false);
				set_all_states(&params->philos[0], DEAD);
				break ;
			}
			i++;
		}
		usleep(SLEEP_BUFFER);
	}
	return (NULL);
}
