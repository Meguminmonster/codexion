/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:59:58 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:00:03 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	release_dongles(t_coder *coder, t_data *data)
{
	long long	curr_time;

	curr_time = get_sim_time(data);
	coder->left_dongle->cooldown = curr_time + data->dongle_cooldown;
	if (coder->right_dongle != NULL)
		coder->right_dongle->cooldown = curr_time + data->dongle_cooldown;
	pthread_mutex_unlock(&coder->left_dongle->lock);
	if (coder->right_dongle != NULL)
		pthread_mutex_unlock(&coder->right_dongle->lock);
	if (is_fifo(data))
	{
		pthread_mutex_lock(&data->queue_control.lock);
		pthread_cond_broadcast(&data->queue_control.cond);
		pthread_mutex_unlock(&data->queue_control.lock);
	}
	else
	{
		pthread_mutex_lock(&data->heap_control.lock);
		pthread_cond_broadcast(&data->heap_control.cond);
		pthread_mutex_unlock(&data->heap_control.lock);
	}
}

int	try_take_dongle(t_dongle *dongle, t_data *data)
{
	pthread_mutex_lock(&dongle->lock);
	if (get_sim_time(data) >= dongle->cooldown)
		return (0);
	pthread_mutex_unlock(&dongle->lock);
	return (1);
}
