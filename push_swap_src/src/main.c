/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 05:52:30 by coremart          #+#    #+#             */
/*   Updated: 2019/04/25 20:09:01 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static int	usage(void)
{
	return (0);
}

int		main(int ac, char **av)
{
	t_arr		*arr;
	int			*lis;
	t_llist		*ll_lis;
	t_piles		*piles;
	t_data_buff data_buff;
	t_all_data	all_data;

	if (ac < 2)
		return (usage());
	arr = pars((const char**)&av[1], ac - 1);
	lis = get_lis_index(arr->arr, (arr->size + 1) >> 1);
	ll_lis = transform_to_ll_lis(arr, lis);
	piles = transform_to_pile(arr);
	data_buff.index = -1;
	all_data.buff = &data_buff;
	all_data.piles = piles;
	all_data.lis = ll_lis;
/*
	t_llist *end_lis = all_data.lis;
	do
	{
		printf("lis :%d\n", all_data.lis->nb);
		all_data.lis = all_data.lis->next;
	}
	while (all_data.lis != end_lis);
	exit(0);
*/
	start_sort_pile(&all_data, (arr->size + 1) >> 1);
	empty_b(&all_data);
	rot_a(&piles->a, (arr->size + 1) >> 1, &data_buff);
	printf("res :\n");
	write_buff(&data_buff);

	printf("a :\n");
	t_llist *end_a = piles->a;
	do
	{
		printf("%d\n", piles->a->nb);
		piles->a = piles->a->next;
	}
	while (piles->a != end_a);
	if (!piles->b)
		printf("b's empty !!!!!!!");
	else
		printf("NOOOOOOOOOOOOO\n");

	return (0);
}
