/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:04:18 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:04:21 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc != 9)
		return (print_error(print_usage(), NULL, &data));
	if (check_arg(&data, argv) == 1)
		return (1);
	init_mutex(&data);
	init_thread(&data);
	join_thread(&data);
	destroy_mutex(&data);
	free_memory(&data);
	return (0);
}
