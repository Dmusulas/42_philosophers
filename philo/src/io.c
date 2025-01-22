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
static int	ft_is_integer(char *str)
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
 * @brief Checks if the given character is a whitespace character.
 *
 * Evaluates whether the character belongs to the set of standard
 * whitespace characters.
 *
 * @param c The character to evaluate.
 * @return 1 if the character is whitespace, 0 otherwise.
 */
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

void	print_msg(t_params *params, int id, char *msg)
{
	pthread_mutex_lock(&params->mut_print);
	if (get_run(params))
		printf("%ld %d %s\n", get_mtime() - get_time_start(params), id, msg);
	pthread_mutex_unlock(&params->mut_print);
}

/**
 * @brief Converts a string to an integer.
 *
 * Parses the string to calculate its integer representation, handling
 * optional leading signs.
 *
 * @param nptr Pointer to the string to convert.
 * @return The integer representation of the string.
 */
long	ft_atoi(const char *nptr)
{
	long	nbr;
	int		i;
	int		sign;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+' || nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
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
	exit_status = 0;
	while (argv[i])
	{
		if (!ft_is_integer(argv[i]))
		{
			help_msg("Incorect input non-integer detected: ", argv[i]);
			exit_status = 1;
			break ;
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			help_msg("Incorect input non-positive input detected: ", argv[i]);
			exit_status = 1;
			break ;
		}
		i++;
	}
	return (exit_status);
}
