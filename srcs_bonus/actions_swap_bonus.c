/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:13:24 by lsun              #+#    #+#             */
/*   Updated: 2023/07/04 19:17:37 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_ps *ps)
{
	int	temp;

	if (ps->len_a < 2)
		return ;
	temp = ps->a[0];
	ps->a[0] = ps->a[1];
	ps->a[1] = temp;
	ps->action_count++;
}

void	sb(t_ps *ps)
{
	int	temp;

	if (ps->len_b < 2)
		return ;
	temp = ps->b[0];
	ps->b[0] = ps->b[1];
	ps->b[1] = temp;
	ps->action_count++;
}

void	ss(t_ps *ps)
{
	if (ps->len_a < 2 || ps->len_b < 2)
		return ;
	sa(ps);
	sb(ps);
	ps->action_count++;
}
