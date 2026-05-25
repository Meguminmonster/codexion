/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:02:50 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:02:52 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	init_mutex_cond(t_data *data);
static void	init_dongles_mutex(t_data *data);

/**
 * Initialize all mutex needed by the program.
 */

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_simu, NULL);
	pthread_mutex_init(&data->queue_control.lock, NULL);
	pthread_mutex_init(&data->heap_control.lock, NULL);
	init_dongles_mutex(data);
	init_mutex_cond(data);
}

/**
 * Init the variable condition for the queue system.
 */

static void	init_mutex_cond(t_data *data)
{
	pthread_cond_init(&data->queue_control.cond, NULL);
	pthread_cond_init(&data->heap_control.cond, NULL);
}

/**
 * Initialize mutex for each dongle and coder like the mutex for the burnout,
 * or the dongle.
 */

static void	init_dongles_mutex(t_data *data)
{
	int	index;

	index = 0;
	while (index != data->nbr_coders)
	{
		pthread_mutex_init(&data->dongle[index].lock, NULL);
		pthread_mutex_init(&data->coder[index].mutex_burnout, NULL);
		pthread_mutex_init(&data->coder[index].mutex_finish, NULL);
		index++;
	}
}
