/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:04:12 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:18:53 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "timer.h"
#include "stdio.h"

void	print_fork_take_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	printf("%lld %i has taken a fork\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_sleeping_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is sleeping\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_eating_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is eating\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_thinking_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is thinking\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_death_message(t_philo *philo, int64_t death_time)
{
	printf("%lld %i died\n", death_time, philo->id);
}
