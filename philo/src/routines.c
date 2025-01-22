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

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo))
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo))
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (think(philo))
			break ;
	}
	return (NULL);
}
