/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:33:55 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:11:58 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

// Start counting milliseconds from the program beginning
void	start_program_timer(void);

// Get time in milliseconds passed from the beginning of the program
int64_t	get_timestamp_in_ms(void);

#endif
