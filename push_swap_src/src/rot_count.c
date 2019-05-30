/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 00:40:09 by coremart          #+#    #+#             */
/*   Updated: 2019/05/30 18:05:39 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

size_t		lst_len(t_llist *lst)
{
	t_llist	*end_lst;
	size_t	i;

	if (!lst)
		return (0);
	end_lst = lst;
	lst = lst->next;
	i = 1;
	while (lst != end_lst)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}

size_t		rot_count_til_push(t_llist *a, t_llist *lis, size_t size, int rev)
{
	size_t	rot_count;
	int		offset;

	rot_count = 0;
	offset = (rev) ? sizeof(t_llist*) : 0;
	while (a->nb == lis->nb)
	{
		lis = *(t_llist**)((char*)lis + offset);
		a = *(t_llist**)((char*)a + offset);
		if (++rot_count == size)
			break ;
	}
	return (rot_count);
}

size_t		count_rot_to_end_of_pa(int *arr, ssize_t rot_to_last,
									t_llist_tmp *b, int rev)
{
	size_t	count;
	size_t	i;
	int		last_b;

	i = 0;
	count = 0;
	if (rot_to_last == -1)
		return (0);
	while (rot_to_last--)
		b = b->next;
	last_b = (rev) ? ~b->nb + 1 : b->nb;
	while (arr[i] != -1)
	{
		if (((rev) ? ~arr[i] + 1 : arr[i]) > last_b)
			++count;
		++i;
	}
	return (count + !rev);
}

size_t		transformed_r_to_rr(int rot_to_first_pa, t_data_buff *buff, int rev)
{
/*	(void)rot_to_first_pa;
	(void)buff;
	(void)rev;
	return (0);
*/	ssize_t	index_tmp;
	int		op;

	index_tmp = buff->index;
	op = (rev) ? RRA : RA;
	while (index_tmp >= 0 && buff->buff[index_tmp] == op
			&& buff->index - index_tmp != rot_to_first_pa)
		--index_tmp;
//	if (index_tmp - index_tmp)
//		printf("%lu\n", buff->index - index_tmp);
	return (buff->index - index_tmp);
}
