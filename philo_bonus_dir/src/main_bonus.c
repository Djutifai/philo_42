/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:12:59 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:06:04 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "philosopher_bonus.h"
#include "philo_bonus.h"
#include "timer_bonus.h"

static void	destroy_all(t_philo *philos)
{
	sem_unlink(PRINT_SEM);
	sem_unlink(FORKS_SEM);
	sem_unlink(EAT_ENOUGH_SEM);
	sem_unlink(STOP_SEM);
	free(philos);
}

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	t_params		params;

	start_program_timer();
	if (validate_and_parse_input(argc, argv, &params) != 0)
		return (-1);
	if (create_philos(params, &philos) != 0)
		return (-1);
	if (philos == NULL)
		return (-1);
	if (create_processes(params.number_of_philos, philos) != 0)
		return (-1);
	kill_processes(philos, params.number_of_philos);
	destroy_all(philos);
	return (0);
}
