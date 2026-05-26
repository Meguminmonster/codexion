/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:58:23 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 15:58:35 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	debug_print_queue(t_queue_manager *manager)
{
	int		count;
	t_queue	*current;

	count = 0;
	current = manager->first;
	while (current != NULL)
	{
		printf("[Queue %d] Coder %d\n", count, current->coder->id);
		count++;
		current = current->next;
	}
}
