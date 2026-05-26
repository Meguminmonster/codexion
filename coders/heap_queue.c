/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:03:42 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/05/25 16:03:47 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	heap_check_deadline(t_heap	*manager, int i);
static int	heap_compare(t_coder *curr_coder, t_coder *coder);
static void	heap_swap(t_coder **tree, int i, int j);

// Adds a coder to the heap priority queue.

void	heap_push(t_heap *manager, t_coder *coder)
{
	int	i;

	i = manager->size;
	manager->tree[i] = coder;
	manager->size += 1;
	while (i > 0)
	{
		if (heap_compare(manager->tree[i], manager->tree[(i - 1) / 2]))
		{
			heap_swap(manager->tree, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
		else
			break ;
	}
}

// Removes a specific coder from the queue.

void	heap_pop(t_heap *manager, t_coder *coder)
{
	int	i;

	i = 0;
	while (i < manager->size)
	{
		if (manager->tree[i] == coder)
			break ;
		i++;
	}
	if (i == manager->size)
		return ;
	manager->size--;
	manager->tree[i] = manager->tree[manager->size];
	while (i > 0 && heap_compare(manager->tree[i], manager->tree[(i - 1) / 2]))
	{
		heap_swap(manager->tree, i, (i - 1) / 2);
		i = (i - 1) / 2;
	}
	heap_check_deadline(manager, i);
}

// If a child has a more urgent deadline, the elements are swapped.

static void	heap_check_deadline(t_heap	*manager, int i)
{
	int	left;
	int	right;
	int	smallest;

	while ((i * 2) + 1 < manager->size)
	{
		left = (i * 2) + 1;
		right = (i * 2) + 2;
		smallest = left;
		if (right < manager->size && heap_compare(manager->tree[right],
				manager->tree[left]))
		{
			smallest = right;
		}
		if (heap_compare(manager->tree[smallest], manager->tree[i]))
		{
			heap_swap(manager->tree, i, smallest);
			i = smallest;
		}
		else
			break ;
	}
}

static int	heap_compare(t_coder *curr_coder, t_coder *coder)
{
	return (get_burnout(curr_coder) < get_burnout(coder));
}

static	void	heap_swap(t_coder **tree, int i, int j)
{
	t_coder	*temp;

	temp = tree[i];
	tree[i] = tree[j];
	tree[j] = temp;
}
