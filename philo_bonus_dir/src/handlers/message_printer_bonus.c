/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:04:12 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:26:55 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosopher_bonus.h"
#include "timer_bonus.h"

void	print_fork_take_message(t_philo *philo)
{
	int64_t	timestamp;

	sem_wait(philo->s_ctx.print_sem);
	timestamp = get_timestamp_in_ms();
	printf("%lld %i has taken a fork\n", timestamp, philo->id);
	sem_post(philo->s_ctx.print_sem);
}

void	print_sleeping_message(t_philo *philo)
{
	int64_t	timestamp;

	sem_wait(philo->s_ctx.print_sem);
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is sleeping\n", timestamp, philo->id);
	sem_post(philo->s_ctx.print_sem);
}

void	print_eating_message(t_philo *philo)
{
	int64_t	timestamp;

	sem_wait(philo->s_ctx.print_sem);
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is eating\n", timestamp, philo->id);
	sem_post(philo->s_ctx.print_sem);
}

void	print_thinking_message(t_philo *philo)
{
	int64_t	timestamp;

	sem_wait(philo->s_ctx.print_sem);
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is thinking\n", timestamp, philo->id);
	sem_post(philo->s_ctx.print_sem);
}

void	print_death_message(t_philo *philo, int64_t death_time)
{
	printf("%lld %i died\n", death_time, philo->id);
}
