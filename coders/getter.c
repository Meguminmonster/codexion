/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:23:22 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:23:36 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Function to know if the simulation is activate or not.

int	get_simulation(t_data *data)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&data->mutex_simu);
	status = data->simulation_active;
	pthread_mutex_unlock(&data->mutex_simu);
	return (status);
}

// Function to retrieve the timestamp at which a coder will burn out.

long long	get_burnout(t_coder *coder)
{
	long long	burnout;

	burnout = 0;
	pthread_mutex_lock(&coder->mutex_burnout);
	burnout = coder->time_bournout;
	pthread_mutex_unlock(&coder->mutex_burnout);
	return (burnout);
}

// Function to check if a coder has reached the required number of compilations.

int	get_have_finished(t_coder *coder)
{
	int	finished;

	finished = 0;
	pthread_mutex_lock(&coder->mutex_finish);
	finished = coder->have_finished;
	pthread_mutex_unlock(&coder->mutex_finish);
	return (finished);
}
