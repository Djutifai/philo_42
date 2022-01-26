/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:31:57 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:29:40 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_FUNCS_BONUS_H
# define FORK_FUNCS_BONUS_H

# include "philosopher_bonus.h"

void	fold_forks_on_stop(t_philo *philo);

void	take_left_fork(t_philo *philo);

void	take_right_fork(t_philo *philo);

#endif
