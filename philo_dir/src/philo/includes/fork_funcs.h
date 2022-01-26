/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:31:57 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:19:49 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_FUNCS_H
# define FORK_FUNCS_H

# include "philosopher.h"

void	fold_forks_on_stop(t_philo *philo);

void	take_left_fork(t_philo *philo);

void	take_right_fork(t_philo *philo);

#endif
