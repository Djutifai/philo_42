/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:20:37 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:23:11 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_PRINTER_BONUS_H
# define MESSAGE_PRINTER_BONUS_H

# include "philosopher_bonus.h"

void	print_fork_take_message(t_philo *philo);

void	print_eating_message(t_philo *philo);

void	print_sleeping_message(t_philo *philo);

void	print_thinking_message(t_philo *philo);

void	print_death_message(t_philo *philo, int64_t death_time);

#endif
