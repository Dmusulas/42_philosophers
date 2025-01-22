/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:29:47 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/17 19:29:47 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Displays an error message and help information.
 *
 * Prints the provided error message and usage instructions for the
 * philosopher simulation.
 *
 * @param err Pointer to the error message string.
 */
void	help_msg(char *err)
{
	if (err)
		printf("ERROR: %s\n", err);
	printf("============== Philosophers help ===============\n");
	printf("Run philosophers simulation, \
usage: ./philo <number_of_philosophers>\n");
	printf("<time_to_die> <time_to_eat time_to_sleep> \
<number_of_times_each_philosopher_must_eat>\n");
	printf("==================================================\n");
}

void	print_msg(t_params *params, int id, char *msg)
{
	time_t	time;

	time = get_time() - get_time_start(params);
	pthread_mutex_lock(&params->mut_print);
	if (get_run(params))
		printf("%ld %d %s\n", time, id, msg);
	pthread_mutex_unlock(&params->mut_print);
}
