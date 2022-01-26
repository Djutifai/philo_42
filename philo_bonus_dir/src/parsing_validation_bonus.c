/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validation_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:13:27 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:06:04 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils_bonus.h"
#include "philo_bonus.h"

static int	validate_numeric_values(int count, char *args[])
{
	while (count > 0)
	{
		if (!ft_is_number(args[count - 1]))
		{
			printf("Please, enter only numeric values as arguments!\n");
			return (-1);
		}
		count--;
	}
	return (0);
}

static int	validate_number_of_args(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong arguments count!\n");
		printf("Right usage:");
		printf("./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat] \n");
		return (-1);
	}
	return (0);
}

int	validate_and_parse_input(int argc, char *argv[], t_params *params)
{
	if (validate_number_of_args(argc) != 0)
		return (-1);
	if (validate_numeric_values(argc - 1, argv + 1) != 0)
		return (-1);
	params->number_of_philos = ft_atol(argv[1]);
	params->time_to_die = ft_atol(argv[2]);
	params->time_to_eat = ft_atol(argv[3]);
	params->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		params->num_of_eats = ft_atol(argv[5]);
	else
		params->num_of_eats = NOTDEFINED;
	return (0);
}
