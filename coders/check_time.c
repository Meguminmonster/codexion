/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:22:38 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:22:41 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/**
 * Gets the time using gettimeofday and converts the
 * seconds and microseconds into a milliseconds value. 
 */

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// Compares the current system time with the recorded start time.

long long	get_sim_time(t_data *data)
{
	return (get_time_ms() - data->start_time);
}
