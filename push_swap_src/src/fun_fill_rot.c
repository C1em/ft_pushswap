/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_fill_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:22:20 by coremart          #+#    #+#             */
/*   Updated: 2019/05/05 01:21:51 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void inline	put_in_buff(t_data_buff *buff, int op)
{
	if (buff->index == 1023)
		write_buff(buff);
	++buff->index;
	buff->buff[buff->index] = op;
}

void				fill_rot_a(t_data_buff *buff)
{
	ssize_t i;

	if (buff->buff[buff->index] & RRA)
		--buff->index;
	else if (buff->buff[buff->index] & RB)
	{
		i = buff->index;
		while (i + (ssize_t)1 && buff->buff[i] & RB)
			--i;
		buff->buff[i + 1] = RR;
	}
	else
	{
		i = buff->index;
		while (i && buff->buff[i] & (RRB | RB | SB))
			--i;
		if (buff->buff[i] & RRR)
			buff->buff[i] = RRB;
		else
			put_in_buff(buff, RA);
	}
}

void				fill_rot_b(t_data_buff *buff)
{
	ssize_t i;

	if (buff->buff[buff->index] & RRB)
		--buff->index;
	else if (buff->buff[buff->index] & RA)
	{
		i = buff->index;
		while (i + (ssize_t)1 && buff->buff[i] & RA)
			--i;
		buff->buff[i + 1] = RR;
	}
	else
	{
		i = buff->index;
		while (i && buff->buff[i] & (RRA | RA | SA))
			--i;
		if (buff->buff[i] & RRR)
			buff->buff[i] = RRA;
		else
			put_in_buff(buff, RB);
	}
}

void				fill_rev_rot_a(t_data_buff *buff)
{
	ssize_t i;

	i = buff->index;
	while (i && (buff->buff[i] & (RB | RRB | SB)))
		--i;
	if (buff->buff[i] & PB && i && buff->buff[i - 1] & RA)
	{
		buff->buff[i - 1] = SA;
		return ;
	}
	if (buff->buff[buff->index] & RA)
		--buff->index;
	else if (buff->buff[buff->index] & RRB)
	{
		i = buff->index;
		while (i + (ssize_t)1 && buff->buff[i] & RRB)
			--i;
		buff->buff[i + 1] = RRR;
	}
	else if (buff->buff[i] & RR)
		buff->buff[i] = RB;
	else
		put_in_buff(buff, RRA);
}

void				fill_rev_rot_b(t_data_buff *buff)
{
	ssize_t i;

	i = buff->index;
	while (i && (buff->buff[i] & (RA | RRA | SA)))
		--i;
	if (buff->buff[i] & PA && i && buff->buff[i - 1] & RB)
	{
		buff->buff[i - 1] = SB;
		return ;
	}
	if (buff->buff[buff->index] & RB)
		--buff->index;
	else if (buff->buff[buff->index] & RRA)
	{
		i = buff->index;
		while (i + (ssize_t)1 && buff->buff[i] & RRA)
			--i;
		buff->buff[i + 1] = RRR;
	}
	else if (buff->buff[i] & RR)
		buff->buff[i] = RA;
	else
		put_in_buff(buff, RRB);
}
