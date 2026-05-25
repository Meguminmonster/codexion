/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scheduler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:22:20 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:22:25 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/**
 * Check if the scheduler used is 'fifo'. If that the case, return '1' (True),
 * otherwise return '0' (False).
 */

int	is_fifo(t_data *data)
{
	if (strcmp(FIFO, data->scheduler) == 0)
		return (1);
	return (0);
}
