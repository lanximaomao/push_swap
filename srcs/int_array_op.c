/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:03:59 by lsun              #+#    #+#             */
/*   Updated: 2023/07/04 19:18:00 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	remove_one_num_front(t_ps *ps)
{
	int	i;
	int	*num_minus;

	i = 0;
	num_minus = malloc(sizeof(int) * (ps->lvl - 1));
	if (!num_minus)
		error("malloc failure", 1);
	while (i + 1 < ps->lvl)
	{
		num_minus[i] = ps->lvl_b[i + 1];
		i++;
	}
	free(ps->lvl_b);
	ps->lvl_b = num_minus;
}

void	add_one_num_front(t_ps *ps, int data)
{
	int	i;
	int	*num_add;

	i = 1;
	num_add = malloc(sizeof(int) * (ps->lvl + 1));
	if (!num_add)
		error("malloc failure", 1);
	num_add[0] = data;
	while (i < ps->lvl + 1)
	{
		num_add[i] = ps->lvl_b[i - 1];
		i++;
	}
	free(ps->lvl_b);
	ps->lvl_b = num_add;
}
