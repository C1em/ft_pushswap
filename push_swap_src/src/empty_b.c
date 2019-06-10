/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:05:27 by coremart          #+#    #+#             */
/*   Updated: 2019/06/10 06:17:22 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t		count_rot_til_destof(t_llist_tmp *b, t_llist *a,
											size_t size, int rev)
{
	size_t	rot_count;
	int		offset;

	rot_count = 0;
	offset = (rev) ? sizeof(t_llist*) : 0;
	while (!is_destof(b, a->nb))
	{
		a = *(t_llist**)((char*)a + offset);
		if (++rot_count == size)
			break ;
	}
	return (rot_count);
}

static size_t		rot_count_after_empty(t_llist *a, size_t rot_count,
											size_t size, int rev)
{
	int offset;

	offset = (rev) ? sizeof(t_llist*) : 0;
	while (rot_count--)
		a = *(t_llist**)((char*)a + offset);
	rot_count = 0;
	while (a->nb > a->prev->nb)
	{
		a = a->next;
		++rot_count;
	}
	if (rot_count > (size >> 1))
		return (size - rot_count);
	return (rot_count);
}

static void			push_all(t_all_data *data, t_llist *end_a,
												size_t rot_count, int rev)
{
	int		max_elem;
	int		op;
	size_t	offset;

	op = (rev) ? RRA : RA;
	offset = (rev) ? sizeof(t_llist*) : 0;
	while (rot_count--)
		fill_buffer(data->buff, op);
	max_elem = len_b(data->piles->b);
	max_elem -= pusha_if_destof(data, max_elem, rev);
	while (data->piles->a != end_a)
	{
		data->piles->a = *(t_llist**)((char*)data->piles->a + offset);
		fill_buffer(data->buff, op);
		max_elem -= pusha_if_destof(data, max_elem, rev);
	}
	(void)pusha_if_destof(data, max_elem, rev);
}

void				empty_b(t_all_data *data, size_t size)
{
	size_t	til_push;
	size_t	rev_til_push;
	size_t	to_smallest;
	size_t	rev_to_smallest;

	if (!data->piles->b || (til_push = count_rot_til_destof(data->piles->b,
		data->piles->a->next, size, 0) + 1) == size)
		return ;
	rev_til_push = count_rot_til_destof(data->piles->b, data->piles->a,
										size, 1);
	to_smallest = rot_count_after_empty(data->piles->a, til_push, size, 0);
	rev_to_smallest = rot_count_after_empty(data->piles->a,
											rev_til_push, size, 1);
	if (til_push + rev_to_smallest >= rev_til_push + to_smallest
		|| (rev_til_push + to_smallest - til_push - rev_to_smallest)
		+ ((rev_til_push + to_smallest - til_push - rev_to_smallest) >> 1)
		<= (size_t)len_b(data->piles->b))
	{
		data->piles->a = rot_pile(rev_til_push, data->piles->a, 1);
		return (push_all(data, rot_pile(til_push, data->piles->a, 0),
				rev_til_push, 1));
	}
	data->piles->a = rot_pile(til_push, data->piles->a, 0);
	return (push_all(data, rot_pile(rev_til_push, data->piles->a, 1),
			til_push, 0));
}
