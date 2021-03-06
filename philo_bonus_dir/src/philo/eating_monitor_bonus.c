/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_monitor_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:58:47 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:29:50 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*start_eating_monitor(void *arg)
{
	t_sem_context	*sem_context;
	int				i;

	sem_context = (t_sem_context *)arg;
	i = -1;
	sem_wait(sem_context->print_sem);
	while (++i < sem_context->number_of_philos)
	{
		sem_post(sem_context->print_sem);
		sem_wait(sem_context->eat_enough_sem);
		sem_wait(sem_context->print_sem);
	}
	sem_post(sem_context->stop_sem);
	return (NULL);
}
