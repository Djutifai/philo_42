/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp_maker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:24:15 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/26 15:29:06 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static int64_t	*get_start_time(void)
{
	static int64_t	start_time;

	return (&start_time);
}

void	start_program_timer(void)
{
	int64_t	*start_time;

	start_time = get_start_time();
	*start_time = gettime_in_ms();
}

int64_t	get_timestamp_in_ms(void)
{
	int64_t	*start_time;

	start_time = get_start_time();
	return (gettime_in_ms() - *start_time);
}
