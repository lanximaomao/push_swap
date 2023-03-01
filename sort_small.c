/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:20:04 by lsun              #+#    #+#             */
/*   Updated: 2023/03/02 00:33:07 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort_top_three_a(ps);
	if (is_sorted (ps->a, ps->len_a) == 0)
	{
		rra(ps);
		sort_top_three_a(ps);
	}
	//ft_printf("after sorting: ");
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_printf("\n");
}

void sort_five_a(t_ps *ps)
{
	//pb(ps);
	//sort_four_a(ps);
	//pa(ps);
	//sort_four_a(ps);
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
	//ft_printf("--- after top three a---\n");
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_printf("\n");
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
	//ft_printf("--- sorting small b ---\n");
	//ft_print_int_array(ps->b, ps->len_b);
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

void push_less_than_three_b_to_a(t_ps *ps, int range)
{
	if(range == 2)
		push_two_b_to_a(ps);
	if (range == 3)
		push_three_b_to_a(ps);
}

void push_three_b_to_a(t_ps *ps)
{
	if (ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2])
		pa(ps);
	else if (ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
	{
		sb(ps);
		pa(ps);
	}
	else if (ps->b[2] > ps->b[0] && ps->b[2] > ps->b[1])
	{
		rb(ps);
		rb(ps);
		pa(ps);
		rrb(ps);
		rrb(ps);
	}
	push_two_b_to_a(ps);
}

void push_two_b_to_a(t_ps *ps)
{
	if (ps->b[0] < ps->b[1])
		sb(ps);
	pa(ps);
	pa(ps);
}


