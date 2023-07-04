/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:14:40 by lsun              #+#    #+#             */
/*   Updated: 2023/07/04 19:18:26 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*  works for the total stack size is 2/3/4/5 */

void	sort_small_a(t_ps *ps)
{
	if (ps->len_a == 2)
		sort_two_a(ps);
	if (ps->len_a == 3)
		sort_three_a(ps);
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
