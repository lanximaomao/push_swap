/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:20:04 by lsun              #+#    #+#             */
/*   Updated: 2023/03/06 17:16:37 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_top_a(t_ps *ps, int range)
{
	int count;

	count = 0;
	if (range == 2)
		sort_two_a(ps);
	if (range == 3)
	{
		if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
			ra(ps);
		else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
		{
			rra(ps);
			count++;
		}
		if (count > 0)
			ra(ps);
		if (ps->a[0] > ps->a[1])
			sa(ps);
	}
}


void sort_small_a(t_ps *ps)
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

void sort_two_a(t_ps *ps)
{
	if(ps->a[0] < ps->a[1])
		return;
	sa(ps);
}

void sort_three_a(t_ps *ps)
{
	if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
		ra(ps);
	else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
		rra(ps);
	if (ps->a[0] > ps->a[1])
		sa(ps);
}

void sort_four_a(t_ps *ps)
{
	optimizer(ps);
	while (ps->a[0] != find_min(ps->a, 0, ps->len_a - 1))
		ra(ps);
	pb(ps);
	sort_three_a(ps);
	pa(ps);
}

void sort_five_a(t_ps *ps)
{
	optimizer(ps);
	while (ps->a[0] != find_min(ps->a, 0, ps->len_a - 1))
		ra(ps);
	pb(ps);
	sort_four_a(ps);
	pa(ps);
}

void optimizer(t_ps *ps)
{
	int i;

	i = ps->len_a/2;
	while (i > 0)
	{
		if (ps->a[ps->len_a-i] == find_min(ps->a, 0, ps->len_a - 1))
			rra(ps);
		i--;
	}
	if (is_sorted(ps->a, ps->len) == 1)
		exit(0);
}

void sort_top_three_a(t_ps *ps)
{
	if (ps->a[0] > ps->a[1])
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



void sort_top_three_b(t_ps *ps) // double check
{
	if (ps->b[0] < ps->b[1])
		sb(ps);
	if (ps->b[1] < ps->b[0] && ps->b[1] < ps->b[2])
	{
		rb(ps);
		sb(ps);
		rrb(ps);
	}
	if (ps->b[0] < ps->b[1])
		sb(ps);
}

void sort_top_small_b(t_ps *ps, int range) // double check
{
	if (range == 2)
		sort_two_b(ps);
	if (range == 3)
	{
		sort_top_three_b(ps);
		pa(ps);
	}
	pa(ps);
	pa(ps);
}

void sort_small_b(t_ps *ps)
{
	int i;

	i = 0;
	if (ps->len_b == 1)
		exit(0);
	if (ps->len_b == 2)
		sort_two_b(ps);
	if (ps->len_b == 3)
		sort_three_b(ps);
	while (ps->len_b != 0)
		pa(ps);
}

void sort_two_b(t_ps *ps)
{
	if(ps->b[0] > ps->b[1])
		return;
	sb(ps);
}

void sort_three_b(t_ps *ps)
{
	if (ps->b[0] < ps->b[1] && ps->b[0] < ps->b[2])
		rb(ps);
	else if (ps->b[1] < ps->b[0] && ps->b[1] < ps->b[2])
		rrb(ps);
	if (ps->b[0] < ps->b[1])
		sb(ps);
}

void push_less_than_five_b_to_a(t_ps *ps, int range)
{
	if(range == 2)
		push_two_b_to_a(ps);
	if (range == 3)
		push_three_b_to_a(ps);
	if (range == 4)
		push_four_b_to_a(ps);
	if (range == 5)
		push_five_b_to_a(ps);
}

void optimizer_b(t_ps *ps)
{
	int i;

	i = ps->len_b/2;
	while (i > 0)
	{
		if (ps->b[ps->len_b-i] == find_max(ps->b, 0, ps->len_b - 1))
			rrb(ps);
		i--;
	}
}

void push_five_b_to_a(t_ps *ps)
{
	int i;

	i = 0;
	optimizer_b(ps);
	while (ps->b[0] != find_max(ps->b, 0, ps->len_b - 1))
		rb(ps);
	pa(ps);
	push_four_b_to_a(ps);
}

void push_four_b_to_a(t_ps *ps)
{
	int i;

	i = 0;
	optimizer_b(ps);
	while (ps->b[0] != find_max(ps->b, 0, ps->len_b - 1))
		rb(ps);
	pa(ps);
	push_three_b_to_a(ps);
}

//update
void push_three_b_to_a(t_ps *ps)
{
	if (ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
		sb(ps);
	else if (ps->b[2] > ps->b[0] && ps->b[2] > ps->b[1])
		rrb(ps);
	pa(ps);
	push_two_b_to_a(ps);
}

void push_two_b_to_a(t_ps *ps)
{
	if (ps->b[0] < ps->b[1])
		sb(ps);
	pa(ps);
	pa(ps);
}
