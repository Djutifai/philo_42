/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_host.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:51:05 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:19:22 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_printer.h"
#include "host.h"
#include "timer.h"

static void	*stop_execution(t_host host, t_philo dead_philo, \
	int64_t death_time)
{
	int64_t	insurance;

	pthread_mutex_lock(dead_philo.print_mutex);
	print_death_message(&dead_philo, death_time);
	*(host.stop) = true;
	pthread_mutex_unlock(dead_philo.print_mutex);
	insurance = 3000;
	conc_usleep(host.table[0].time_to_eat + \
				host.table[0].time_to_sleep + insurance);
	return (NULL);
}

void	*start_death_host(void *host_arg)
{
	t_host	*host;
	t_philo	philo;
	int64_t	current_time;
	int		count;
	int		finised_count;

	host = (t_host *)host_arg;
	while (true)
	{
		count = 0;
		finised_count = 0;
		current_time = get_timestamp_in_ms();
		while (count < host->number_of_philos)
		{
			philo = host->table[count];
			if (philo.finished == true)
				finised_count++;
			else if (philo.last_meal_time + philo.time_to_die < current_time)
				return (stop_execution(*host, philo, current_time));
			count++;
		}
		if (finised_count >= host->number_of_philos)
			return (NULL);
	}
}
