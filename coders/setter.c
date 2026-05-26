/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:24:14 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:24:17 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	set_burnout(t_coder *coder)
{
	pthread_mutex_lock(&coder->mutex_burnout);
	coder->time_bournout = get_time_ms();
	pthread_mutex_unlock(&coder->mutex_burnout);
}

void	set_finished(t_coder *coder)
{
	pthread_mutex_lock(&coder->mutex_finish);
	coder->have_finished = 1;
	pthread_mutex_unlock(&coder->mutex_finish);
}
