/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:18 by lsun              #+#    #+#             */
/*   Updated: 2023/02/24 13:27:28 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.

void sa(t_ps *ps)
{
	int temp;

	if (ps->len_a < 2)
		return;
	temp = ps->a[0];
	ps->a[0] = ps->a[1];
	ps->a[1] = temp;
	write(1,"sa\n",3);
}

//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.

void sb(t_ps *ps)
{
	int temp;

	if (ps->len_b < 2)
		return;
	temp = ps->b[0];
	ps->b[0] = ps->b[1];
	ps->b[1] = temp;
	write(1,"sb\n",3);
}

//ss : sa and sb at the same time.

void ss(t_ps *ps)
{
	if (ps->len_a < 2 || ps->len_b < 2)
		return;
	sa(ps);
	sb(ps);
}

//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.

void pa(t_ps *ps)
{
	int i;
	int temp;

	if (ps->len_b == 0)
		return;
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
	write(1,"pa\n",3);
}

//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.

void pb(t_ps *ps)
{
	int i;

	int temp;
	if (ps->len_a == 0)
		return;
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
	write(1, "pb\n", 3);
}

//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.

void ra(t_ps *ps)
{
	int i;
	int first;

	i = 1;
	first = ps->a[0];
	while (i < ps->len_a)
	{
		ps->a[i - 1] = ps->a[i];
		i++;
	}
	ps->a[ps->len_a - 1] = first;
	write(1, "ra\n", 3);
}

//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.

void rb(t_ps *ps)
{
	int i;
	int first;

	i = 1;
	first = ps->b[0];
	while (i < ps->len_b)
	{
		ps->b[i - 1] = ps->b[i];
		i++;
	}
	ps->b[ps->len_b - 1] = first;
	write(1, "rb\n", 3);
}

//rr : ra and rb at the same time.

void rr(t_ps *ps)
{
	ra(ps);
	rb(ps);
}

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.

void rra(t_ps *ps)
{
	int i;
	int last;

	i = 0;
	last = ps->a[ps->len_a - 1];

	while (i < ps->len_a)
	{
		ps->a[ps->len_a - i] = ps->a[ps->len_a - 1 - i];
		i++;
	}
	ps->a[0] = last;
	write(1, "rra\n", 4);
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1.

void rrb(t_ps *ps)
{
	int i;
	int last;

	i = 0;
	last = ps->b[ps->len_b - 1];

	while (i < ps->len_b)
	{
		ps->b[ps->len_b - i] = ps->b[ps->len_b - 1 - i];
		i++;
	}
	ps->b[0] = last;
	write(1, "rrb\n", 4);
}

//The last element becomes the first one.
//rrr : rra and rrb at the same time.

void rrr(t_ps *ps)
{
	rra(ps);
	rrb(ps);
}
