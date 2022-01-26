/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:07:30 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:06:45 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "host.h"
#include "utils.h"

int	create_host(t_philo *philos, int number_of_philos, \
	t_bool *stop, t_host *host)
{
	host->table = philos;
	host->number_of_philos = number_of_philos;
	host->stop = stop;
	return (0);
}
