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


int	main(int argc, char *argv[])
{
	t_params	params;

	if (argc < 5 || argc > 6)
	{
		help_msg("Incorrect amount of arguments");
		exit(EXIT_FAILURE);
	}
	if (validate_input(argv))
		exit(EXIT_FAILURE);
	if (init_program(&params, argc, argv))
		exit(EXIT_FAILURE);
	run_threads(&params);
	join_threads(&params);
	free_data(&params);
	return (EXIT_SUCCESS);
}
