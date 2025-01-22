/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:43:51 by dmusulas          #+#    #+#             */
/*   Updated: 2024/12/09 17:43:51 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if the given string represents a valid integer.
 *
 * Evaluates each character in the string to determine if it consists
 * only of digits, optionally preceded by a '+' or '-' sign.
 *
 * @param str The string to evaluate.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
int	ft_is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Validates the input arguments for the philosopher simulation.
 *
 * Ensures all provided arguments are integers and positive values.
 * Displays error messages for invalid inputs.
 *
 * @param argv The array of input arguments to validate.
 * @return 1 if all inputs are valid, 0 otherwise.
 */
int	validate_input(char *argv[])
{
	int	i;
	int	exit_status;

	i = 1;
	exit_status = 1;
	while (argv[i])
	{
		if (!ft_is_integer(argv[i]))
		{
			help_msg("Incorect input: non-integer detected");
			exit_status = 0;
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			help_msg("Incorect input: non-positive input detected");
			exit_status = 0;
		}
		i++;
	}
	return (exit_status);
}
