/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:01:10 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:01:15 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	check_burns_out(t_data *data, int *finish);
static void	stop_simulation(t_data *data);

void	*monitoring_simulation(void *arg)
{
	t_data	*data;
	int		finish;

	data = (t_data *)arg;
	while (get_simulation(data) == 1)
	{
		if (check_burns_out(data, &finish) == 1)
			return (NULL);
		if (finish == data->nbr_coders)
		{
			stop_simulation(data);
			pthread_mutex_lock(&data->mutex_print);
			printf(LOG_SUCCESS "\n");
			pthread_mutex_unlock(&data->mutex_print);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

static int	check_burns_out(t_data *data, int *finish)
{
	int	index;

	index = 0;
	*finish = 0;
	while (data->nbr_coders != index)
	{
		if (get_have_finished(&data->coder[index]) == 1)
			(*finish)++;
		else if ((get_time_ms() - get_burnout(&data->coder[index]))
			> data->burnout_max)
		{
			stop_simulation(data);
			print_logs(data->coder[index].id, 0, ACT_BURNS, data);
			return (1);
		}
		index++;
	}
	return (0);
}

static void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->mutex_simu);
	data->simulation_active = 0;
	pthread_mutex_unlock(&data->mutex_simu);
	pthread_mutex_lock(&data->queue_control.lock);
	pthread_cond_broadcast(&data->queue_control.cond);
	pthread_mutex_unlock(&data->queue_control.lock);
	pthread_mutex_lock(&data->heap_control.lock);
	pthread_cond_broadcast(&data->heap_control.cond);
	pthread_mutex_unlock(&data->heap_control.lock);
}
