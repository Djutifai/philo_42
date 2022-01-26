/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:39:18 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:06:04 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "includes/fork_funcs_bonus.h"
#include "message_printer_bonus.h"

void	take_left_fork(t_philo *philo)
{
	sem_wait(philo->s_ctx.forks_sem);
	print_fork_take_message(philo);
}

void	take_right_fork(t_philo *philo)
{
	sem_wait(philo->s_ctx.forks_sem);
	print_fork_take_message(philo);
}
