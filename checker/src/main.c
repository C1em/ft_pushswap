/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:47:33 by coremart          #+#    #+#             */
/*   Updated: 2019/04/10 12:00:53 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	t_pile	*pile;
	t_pile	*op_pile;
	t_piles *piles;

	pile = pars_pile(&av[1], ac - 1);
	op_pile = get_op();
	piles = apply_op_to_pile(pile, op_pile);
	check_if_order(piles);
}