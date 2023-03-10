/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:20:04 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 13:34:01 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  works for the total stack size is 2/3/4/5 */

void	sort_small_a(t_ps *ps)
{
	if (ps->len_a == 2)
		sort_two_a(ps);
	if (ps->len_a == 3)
		sort_three_a(ps);
	if (ps->len_a == 4)
		sort_four_a(ps);
	if (ps->len_a == 5)
		sort_five_a(ps);
}

void	sort_two_a(t_ps *ps)
{
	if (ps->a[0] < ps->a[1])
		return ;
	sa(ps);
}

void	sort_three_a(t_ps *ps)
{
	if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
		ra(ps);
	else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
		rra(ps);
	if (ps->a[0] > ps->a[1])
		sa(ps);
}

void	sort_four_a(t_ps *ps)
{
	optimizer(ps);
	while (ps->a[0] != find_min(ps->a, 0, ps->len_a - 1))
		ra(ps);
	pb(ps);
	sort_three_a(ps);
	pa(ps);
}

void	sort_five_a(t_ps *ps)
{
	optimizer(ps);
	while (ps->a[0] != find_min(ps->a, 0, ps->len_a - 1))
		ra(ps);
	pb(ps);
	sort_four_a(ps);
	pa(ps);
}
