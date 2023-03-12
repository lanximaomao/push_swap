/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_reverse_rotate_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:14:21 by linlinsun         #+#    #+#             */
/*   Updated: 2023/03/13 00:38:19 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps)
{
	int	i;
	int	last;

	i = 0;
	last = ps->a[ps->len_a - 1];
	while (i < ps->len_a)
	{
		ps->a[ps->len_a - i] = ps->a[ps->len_a - 1 - i];
		i++;
	}
	ps->a[0] = last;
	ps->action_count++;
}

void	rrb(t_ps *ps)
{
	int	i;
	int	last;

	i = 0;
	last = ps->b[ps->len_b - 1];
	while (i < ps->len_b)
	{
		ps->b[ps->len_b - i] = ps->b[ps->len_b - 1 - i];
		i++;
	}
	ps->b[0] = last;
	ps->action_count++;
}

void	rrr(t_ps *ps)
{
	rra(ps);
	rrb(ps);
	ps->action_count++;
}
