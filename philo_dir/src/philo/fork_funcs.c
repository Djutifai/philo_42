/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:39:18 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:19:55 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fork_funcs.h"
#include "pthread.h"
#include "message_printer.h"

void	fold_forks_on_stop(t_philo *philo)
{
	if (philo->has_left_fork)
		pthread_mutex_unlock(philo->left_fork->mutex);
	if (philo->has_right_fork)
		pthread_mutex_unlock(philo->right_fork->mutex);
}

void	take_left_fork(t_philo *philo)
{
	philo->has_left_fork = true;
	pthread_mutex_lock(philo->left_fork->mutex);
	print_fork_take_message(philo);
}

void	take_right_fork(t_philo *philo)
{
	philo->has_right_fork = true;
	pthread_mutex_lock(philo->right_fork->mutex);
	print_fork_take_message(philo);
}
