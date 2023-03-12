/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:19:02 by lsun              #+#    #+#             */
/*   Updated: 2023/03/12 22:59:30 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_algo(t_ps *ps)
{
	optimizer(ps);
	first_divide_a_to_b(ps, ps->len_a);
	while (ps->lvl_b[0] != 0)
	{
		if (is_sorted_reverse(ps->b, ps->lvl_b[0]) == 1)
		{
			push_b2a(ps, ps->lvl_b[0]);
			remove_one_num_front(ps);
		}
		else if (ps->lvl_b[0] <= 3)
		{
			sort_top_b(ps, ps->lvl_b[0]);
			remove_one_num_front(ps);
			ps->lvl--;
		}
		else
			divide_b_to_a(ps, ps->lvl_b[0]);
	}
	return (0);
}

void	first_divide_a_to_b(t_ps *ps, int range)
{
	int	i;
	int	median;
	int	b_init_size;

	i = 0;
	b_init_size = ps->len_b;
	if (ps->len_a <= 3)
	{
		return (sort_small_a(ps));
	}
	median = find_median(ps->a, range);
	while (ps->len_b - b_init_size < range / 2)
	{
		if (ps->a[0] < median || (ps->a[0] == median && range % 2 == 0))
			pb(ps);
		else if (++i)
			ra(ps);
	}
	i = 0;
	if (ps->len_b - b_init_size > 0)
	{
		add_one_num_front(ps, ps->len_b - b_init_size);
		ps->lvl++;
	}
	first_divide_a_to_b(ps, ps->len_a);
}

void	divide_a_to_b(t_ps *ps, int range)
{
	int	i;
	int	median;
	int	b_init_size;

	i = -1;
	b_init_size = ps->len_b;
	if (is_sorted(ps->a, ps->len_a) == 1)
		return ;
	if (range <= 3)
		return (sort_top_a(ps, range));
	median = find_median(ps->a, range);
	while (ps->len_b - b_init_size < range / 2)
	{
		if (ps->a[0] < median)
			pb(ps);
		else if (ps->a[0] == median && range % 2 == 0)
			pb(ps);
		else if (ps->a[0] >= median && ++i)
			ra(ps);
	}
	while (i-- > 0)
		rra(ps);
	if (ps->len_b - b_init_size > 0 && ++ps->lvl)
		add_one_num_front(ps, ps->len_b - b_init_size);
	divide_a_to_b(ps, ps->len - b_init_size - ps->len_a + range % 2);
}

void	divide_b_to_a(t_ps *ps, int range)
{
	int	count;
	int	median;
	int	a_init_size;

	count = -1;
	a_init_size = ps->len_a;
	if (range <= 3 && --ps->lvl)
	{
		sort_top_b(ps, range);
		remove_one_num_front(ps);
	}
	median = find_median(ps->b, range);
	while (ps->len_a - a_init_size < range / 2)
	{
		if (ps->b[0] > median || (ps->b[0] > median && range % 2 == 0))
			pa(ps);
		else if (++count)
			rb(ps);
	}
	while (count-- > 0 && range != ps->len_b)
		rrb(ps);
	ps->lvl_b[0] = ps->lvl_b[0] - (ps->len_a - a_init_size);
	if (ps->len_a - a_init_size <= 3)
		sort_top_a(ps, ps->len_a - a_init_size);
	divide_a_to_b(ps, ps->len_a - a_init_size);
}
