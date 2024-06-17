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
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc >= 5 && argc <= 6)
	{
		// TODO: parsing args and execution
		printf("execute %s", argv[2]);
	}
	else
	{
		help_msg(NULL);
	}
	return (EXIT_SUCCESS);
}
