/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:36:56 by marvin            #+#    #+#             */
/*   Updated: 2022/01/26 15:08:54 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "philosopher.h"
# include "utils.h"

// Parameters passed as arguments
typedef struct s_params
{
	int64_t			time_to_die;
	int64_t			time_to_eat;
	int64_t			time_to_sleep;
	int64_t			num_of_eats;
	int				number_of_philos;
}	t_params;

// Validates the input and returns parsed input
int		validate_and_parse_input(int argc, char *argv[], t_params *params);

// Creates philosophers
int		create_philos(t_params params, t_bool *stop, t_philo **philos_out);

// Starts philosopher lifecycle
void	*start_philo_lifecycle(void *args);

// Starts host lificycle
void	*start_host(void *host_arg);

// Starts death host lifecycle
void	*start_death_host(void *host_arg);

// Creates seats at a round table
int		create_table(t_philo *philos, int number_of_philos);

#endif
