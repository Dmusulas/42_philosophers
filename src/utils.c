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

void	help_msg(char *err)
{
	if (err)
	{
		printf("%s\n", err);
	}
	printf("============== Philosophers help ===============\n");
	printf("Run philosophers simulation, \
usage: ./philo <number_of_philosophers>\n");
	printf("<time_to_die> <time_to_eat time_to_sleep> \
<number_of_times_each_philosopher_must_eat>\n");
	printf("--------------------------------------------------\n");
	printf("Available philosophers programs options: \n");
	printf("\tnumber_of_philosophers - how many philosophers to simulate\n");
	printf("\ttime_to_die (milliseconds)\
- if philosopher has not eaten for this time they die\n");
	printf("\ttime_to_eat (milliseconds)\
- how long does it take for philospher to eat and hold two forks\n");
	printf("\ttime_to_sleep (milliseconds)\
- how long does philosopher sleep\n");
	printf("\tnumber_of_philosophers - how long does philosopher sleep\n");
	printf("\tnumber_of_times_each_philosopher_must_eat [optional]\
- how many times should philosopher eat before simulation stops\n");
	printf("==================================================\n");
}
