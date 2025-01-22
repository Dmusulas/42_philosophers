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

/**
 * @brief Checks if the given character is a whitespace character.
 *
 * Evaluates whether the character belongs to the set of standard
 * whitespace characters.
 *
 * @param c The character to evaluate.
 * @return 1 if the character is whitespace, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
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
