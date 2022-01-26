/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:32:24 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:25:38 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H
# include <semaphore.h>
# include <unistd.h>
# include "utils_bonus.h"

# define NOTDEFINED -1					// Represents undefined value.
# define FORKS_SEM "p_forks"			// Represents forks semaphore name
# define PRINT_SEM "p_print"
# define STOP_SEM "p_stop"
# define EAT_ENOUGH_SEM "p_enough"		// Represents eat enough semaphore name

// Sem context. Shared accross all processes.
typedef struct s_sem_context
{
	sem_t			*print_sem;
	sem_t			*forks_sem;
	sem_t			*stop_sem;
	sem_t			*eat_enough_sem;
	int				number_of_philos;
}	t_sem_context;

// Philosopher
typedef struct s_philo
{
	int				id;
	pid_t			pid;
	int64_t			time_to_die;
	int64_t			time_to_eat;
	int64_t			time_to_sleep;
	int64_t			last_meal_time;
	int64_t			num_of_eats;
	t_sem_context	s_ctx;
}				t_philo;

#endif
