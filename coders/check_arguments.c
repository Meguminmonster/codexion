/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:21:58 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:22:07 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	parse_data(t_data *data, int *arg);

/**
 * Verify that arguments provided by the user are correct, meaning : only
 * integer (except for scheduler that accept either 'fifo' or 'edf',
 * case-sensitive.), greater than 0 and that there are only 8 arguments.
 * Then, parse data and init all structures with provided informations.
 */

int	check_arg(t_data *data, char **arg)
{
	int	i;
	int	parsed_arg[8];

	i = 1;
	while (i != 8)
	{
		parsed_arg[i - 1] = atoi(arg[i]);
		if (parsed_arg[i - 1] >= 1)
		{
			if (i == 1 && parsed_arg[i - 1] >= MAX_CODERS)
				return (print_error(STR_ERR_INV_ARG, arg[i], data));
			i++;
		}
		else
			return (print_error(STR_ERR_INV_ARG, arg[i], data));
	}
	if (parse_data(data, parsed_arg) == 1 || init_struct(data) == 1)
		return (1);
	if (strcmp(FIFO, arg[i]) == 0 || strcmp(EDF, arg[i]) == 0)
		data->scheduler = arg[i];
	else
		return (print_error(STR_ERR_INV_ARG, arg[i], data));
	return (0);
}

/**
 * Parse data provided by user into the data structure. Initialize memory for
 * coders and dongles.
 */

static int	parse_data(t_data *data, int *arg)
{
	data->coder = malloc(sizeof(t_coder) * arg[0]);
	if (data->coder == NULL)
		return (print_error(STR_ERR_MALLOC, NULL, data));
	data->dongle = malloc(sizeof(t_dongle) * arg[0]);
	if (data->dongle == NULL)
		return (print_error(STR_ERR_MALLOC, NULL, data));
	data->nbr_coders = arg[0];
	data->nbr_dongle = arg[0];
	data->burnout_max = arg[1];
	data->time_comp = arg[2];
	data->time_debug = arg[3];
	data->time_refac = arg[4];
	data->compile_required = arg[5];
	data->dongle_cooldown = arg[6];
	return (0);
}
