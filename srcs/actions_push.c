/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:18 by lsun              #+#    #+#             */
/*   Updated: 2023/07/04 19:17:22 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_ps *ps)
{
	int	i;
	int	temp;

	if (ps->len_b == 0)
		return ;
	i = 0;
	temp = ps->b[0];
	while (i < ps->len_b - 1)
	{
		ps->b[i] = ps->b[i + 1];
		i++;
	}
	i = 0;
	while (i < ps->len_a)
	{
		ps->a[ps->len_a - i] = ps->a[ps->len_a - 1 - i];
		i++;
	}
	ps->a[0] = temp;
	ps->len_b--;
	ps->len_a++;
	ps->action_count++;
	write(1, "pa\n", 3);
}

void	pb(t_ps *ps)
{
	int	i;
	int	temp;

	if (ps->len_a == 0)
		return ;
	i = 0;
	temp = ps->a[0];
	while (i < ps->len_a - 1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	i = 0;
	while (i < ps->len_b)
	{
		ps->b[ps->len_b - i] = ps->b[ps->len_b - 1 - i];
		i++;
	}
	ps->b[0] = temp;
	ps->len_a--;
	ps->len_b++;
	ps->action_count++;
	write(1, "pb\n", 3);
}
