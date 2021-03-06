/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:16:11 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:14:19 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "philo.h"

static t_philo	create_philo(t_params params, int64_t philo_id, \
	pthread_mutex_t *print_mutex, t_bool *stop)
{
	t_philo			philo;

	philo.time_to_die = params.time_to_die;
	philo.stop = stop;
	philo.time_to_eat = params.time_to_eat;
	philo.time_to_sleep = params.time_to_sleep;
	philo.num_of_eats = params.num_of_eats;
	philo.last_meal_time = 0;
	philo.id = philo_id;
	philo.print_mutex = print_mutex;
	philo.right_fork = NULL;
	philo.left_fork = NULL;
	philo.has_right_fork = false;
	philo.has_left_fork = false;
	return (philo);
}

int	create_philos(t_params params, t_bool *stop, t_philo **philos_out)
{
	int64_t			count;
	t_philo			*philos;
	pthread_mutex_t	*print_mutex;
	t_bool			opt;

	print_mutex = malloc(sizeof(pthread_mutex_t));
	if (print_mutex == NULL)
		return (-1);
	if (pthread_mutex_init(print_mutex, NULL) != 0)
		return (-1);
	philos = malloc(sizeof(t_philo) * params.number_of_philos);
	if (philos == NULL)
		return (-1);
	if (params.number_of_philos >= 110)
		opt = true;
	else
		opt = false;
	count = -1;
	while (++count < params.number_of_philos)
	{
		philos[count] = create_philo(params, count + 1, print_mutex, stop);
		philos->big_num_optim = opt;
	}
	*philos_out = philos;
	return (0);
}
