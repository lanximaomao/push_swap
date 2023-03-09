/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:21:55 by lsun              #+#    #+#             */
/*   Updated: 2023/03/09 16:17:36 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_top_b(t_ps *ps, int range) // double check
{
	if (ps->b[0] < ps->b[1])
		sb(ps);
	// so the biggest is either at first or last
	if (range == 3 && ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2]) // first is the max
	{
		pa(ps);
		if (ps->b[0] < ps->b[1])
			sb(ps);
	}
	else if (range == 3 && ps->b[2] > ps->b[0] && ps->b[2] > ps->b[1]) // third is the max
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

//void sort_top_small_b(t_ps *ps, int range) // double check
//{
//	if (range == 2)
//		sort_two_b(ps);
//	if (range == 3)
//	{
//		sort_top_three_b(ps);
//		pa(ps);
//	}
//	pa(ps);
//	pa(ps);
//}

//void sort_small_b(t_ps *ps)
//{
//	int i;

//	i = 0;
//	if (ps->len_b == 1)
//		exit(0);
//	if (ps->len_b == 2)
//		sort_two_b(ps);
//	if (ps->len_b == 3)
//		sort_three_b(ps);
//	while (ps->len_b != 0)
//		pa(ps);
//}

//void sort_three_b(t_ps *ps)
//{
//	if (ps->b[0] < ps->b[1] && ps->b[0] < ps->b[2])
//		rb(ps);
//	else if (ps->b[1] < ps->b[0] && ps->b[1] < ps->b[2])
//		rrb(ps);
//	if (ps->b[0] < ps->b[1])
//		sb(ps);
//}






//void push_less_than_five_b_to_a(t_ps *ps, int range)
//{
//	if(range == 2)
//		push_two_b_to_a(ps);
//	if (range == 3)
//		push_three_b_to_a(ps);
//	if (range == 4)
//		push_four_b_to_a(ps);
//	if (range == 5)
//		push_five_b_to_a(ps);
//}

//void push_two_b_to_a(t_ps *ps)
//{
//	if (ps->b[0] < ps->b[1])
//		sb(ps);
//	pa(ps);
//	pa(ps);
//}

//void push_three_b_to_a(t_ps *ps)
//{
//	int count;

//	count = 0;

//	if (ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
//		sb(ps);
//	else if (ps->b[2] > ps->b[0] && ps->b[2] > ps->b[1])
//	{
//		rrb(ps);
//		count++;
//	}
//	while (count > 0)
//	{
//		rb(ps);
//		count--;
//	}
//	pa(ps);
//	push_two_b_to_a(ps);
//}

//void push_four_b_to_a(t_ps *ps)
//{
//	int i;

//	i = 0;
//	optimizer_b(ps);
//	while (ps->b[0] != find_max(ps->b, 0, ps->len_b - 1))
//		rb(ps);
//	pa(ps);
//	push_three_b_to_a(ps);
//}

//void push_five_b_to_a(t_ps *ps)
//{
//	int i;

//	i = 0;
//	optimizer_b(ps);
//	while (ps->b[0] != find_max(ps->b, 0, ps->len_b - 1))
//		rb(ps);
//	pa(ps);
//	push_four_b_to_a(ps);
//}


//void push_n_and_sort_a(t_ps *ps, int range)
//{
//	int i;

//	i = 0;
//	while (i < range)
//	{
//		pa(ps);
//		i++;
//	}
//	sort_top_a(ps, range);
//}
