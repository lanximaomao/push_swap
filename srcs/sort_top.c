/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:34:07 by lsun              #+#    #+#             */
/*   Updated: 2023/07/04 19:18:29 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_top_a(t_ps *ps, int range)
{
	int	count;

	count = 0;
	if (range == 2)
		sort_two_a(ps);
	if (range == 3)
	{
		if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
			sa(ps);
		if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
		{
			ra(ps);
			sa(ps);
			rra(ps);
		}
		if (ps->a[0] > ps->a[1])
			sa(ps);
	}
}

void	sort_top_b(t_ps *ps, int range)
{
	if (ps->b[0] < ps->b[1])
		sb(ps);
	if (range == 3 && ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2])
	{
		pa(ps);
		if (ps->b[0] < ps->b[1])
			sb(ps);
	}
	else if (range == 3 && ps->b[2] > ps->b[0] && ps->b[2] > ps->b[1])
	{
		rb(ps);
		rb(ps);
		pa(ps);
		rrb(ps);
		rrb(ps);
	}
	pa(ps);
	pa(ps);
}

void	push_b2a(t_ps *ps, int range)
{
	while (range > 0)
	{
		pa(ps);
		range--;
	}
}
