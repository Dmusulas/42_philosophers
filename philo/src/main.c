/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:43:57 by dmusulas          #+#    #+#             */
/*   Updated: 2024/06/17 17:48:47 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Displays an error message and help information.
 *
 * Prints the provided error message and usage instructions for the
 * philosopher simulation, including a brief description of the arguments.
 *
 * @param err Pointer to the error message string.
 */
void	help_msg(char *err, char *failing_arg)
{
	if (err && !failing_arg)
		printf("FATAL: %s\n\n", err);
	else if (err && failing_arg)
		printf("FATAL: %s %s\n\n", err, failing_arg);
	printf("============== Philosophers Help ===============\n\n");
	printf("Usage: ./philo <number_of_philosophers> <time_to_die>\n");
	printf("       <time_to_eat> <time_to_sleep>\n");
	printf("       [<number_of_times_each_philosopher_must_eat>]\n\n");
	printf("Arguments:\n");
	printf("  - <number_of_philosophers> (required)\n");
	printf("    Number of philosophers sitting at the table, must be >= 1.\n");
	printf("  - <time_to_die> (required)\n");
	printf("    Time (ms) a philosopher can live without eating, \
must be >= 1.\n");
	printf("  - <time_to_eat> (required)\n");
	printf("    Time (ms) a philosopher spends eating, must be >= 1.\n");
	printf("  - <time_to_sleep> (required)\n");
	printf("    Time (ms) a philosopher spends sleeping, must be >= 1.\n");
	printf("  - [number_of_times_each_philosopher_must_eat] (optional)\n");
	printf("    Number of times each philosopher eats before simulation \
ends.\n\n");
	printf("==================================================\n");
}

int	main(int argc, char *argv[])
{
	t_params	params;

	if (argc < 5 || argc > 6)
	{
		help_msg("Incorrect amount of arguments", NULL);
		exit(EXIT_FAILURE);
	}
	if (validate_input(argv))
		exit(EXIT_FAILURE);
	if (init_program(&params, argc, argv))
		exit(EXIT_FAILURE);
	run_threads(&params);
	join_threads(&params);
	free_params(&params);
	return (EXIT_SUCCESS);
}
