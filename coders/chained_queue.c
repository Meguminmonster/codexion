/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:02:32 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:02:35 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	add_to_queue(t_queue_manager *manager, t_coder *coder_to_add)
{
	t_queue	*node;

	node = malloc(sizeof(t_queue));
	if (node == NULL)
		return (1);
	node->coder = coder_to_add;
	node->next = NULL;
	if (manager->first == NULL)
	{
		manager->first = node;
		manager->last = node;
	}
	else
	{
		manager->last->next = node;
		manager->last = node;
	}
	return (0);
}

int	remove_from_queue(t_queue_manager *manager)
{
	t_queue	*temp;

	if (manager->first == NULL)
		return (1);
	temp = manager->first;
	manager->first = temp->next;
	if (manager->first == NULL)
		manager->last = NULL;
	free (temp);
	return (0);
}
