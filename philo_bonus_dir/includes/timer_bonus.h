/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:33:55 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:25:45 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_BONUS_H
# define TIMER_BONUS_H

// Start counting milliseconds from the program beginning
void		start_program_timer(void);

// Get time in milliseconds passed from the beginning of the program
int64_t		get_timestamp_in_ms(void);

#endif
