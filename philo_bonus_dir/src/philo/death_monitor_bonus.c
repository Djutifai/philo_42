/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:51:05 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:06:04 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_printer_bonus.h"
#include "philosopher_bonus.h"
#include "timer_bonus.h"

static void	*stop_execution(t_philo *dead_philo, \
	int64_t death_time)
{
	sem_wait(dead_philo->s_ctx.print_sem);
	print_death_message(dead_philo, death_time);
	sem_post(dead_philo->s_ctx.stop_sem);
	return (NULL);
}

void	*start_death_monitor(void *philo_arg)
{
	t_philo	*philo;
	int64_t	current_time;

	philo = (t_philo *)philo_arg;
	while (true)
	{
		current_time = get_timestamp_in_ms();
		if (philo->last_meal_time + philo->time_to_die < current_time)
			stop_execution(philo, current_time);
		conc_usleep(5);
	}
}
