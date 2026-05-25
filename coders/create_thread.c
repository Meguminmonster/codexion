/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:03:07 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:03:10 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/**
 * Create all threads needed like the thread for the monitoring and each
 * coder's thread.
 */

void	init_thread(t_data *data)
{
	int	index;

	index = 0;
	pthread_create(&data->monitoring_id, NULL, monitoring_simulation, data);
	while (index != data->nbr_coders)
	{
		pthread_create(&data->coder[index].thread_id, NULL, coder_thread,
			&data->coder[index]);
		index++;
	}
}

/**
 * Pause the main program until each thread have finished to work. In this case,
 * when monitoring put the variable 'simulation_active' to 0.
 */

void	join_thread(t_data *data)
{
	int	index;

	index = 0;
	pthread_join(data->monitoring_id, NULL);
	while (index != data->nbr_coders)
	{
		pthread_join(data->coder[index].thread_id, NULL);
		index++;
	}
}
