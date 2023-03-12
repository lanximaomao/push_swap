/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:40:40 by lsun              #+#    #+#             */
/*   Updated: 2023/03/13 00:10:21 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	int	i;
	int	first;

	i = 1;
	first = ps->a[0];
	while (i < ps->len_a)
	{
		ps->a[i - 1] = ps->a[i];
		i++;
	}
	ps->a[ps->len_a - 1] = first;
	ps->action_count++;
}

void	rb(t_ps *ps)
{
	int	i;
	int	first;

	i = 1;
	first = ps->b[0];
	while (i < ps->len_b)
	{
		ps->b[i - 1] = ps->b[i];
		i++;
	}
	ps->b[ps->len_b - 1] = first;
	ps->action_count++;
}

void	rr(t_ps *ps)
{
	ra(ps);
	rb(ps);
	ps->action_count++;
}
