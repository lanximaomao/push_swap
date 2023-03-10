/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 13:11:44 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps_init(ps, argv);
	sort_algo(ps);
	free(ps->a);
	free(ps->b);
	free(ps->lvl_b);
	free(ps);
	return (0);
}

int	ps_init(t_ps *ps, char **argv)
{
	ps->input = argv + 1;
	check_for_length(ps);
	if (ps->len_a <= 1)
		exit(0);
	ps->a = malloc(sizeof(int) * ps->len_a);
	ps->b = malloc(sizeof(int) * ps->len_a);
	ps->len_b = 0;
	if (!ps->a || !ps->b)
		error("malloc fail", 1);
	is_uniq(parsing(ps));
	ps->action_count = 0;
	if (ps->len_a <= 5)
	{
		sort_small_a(ps);
		exit(0);
	}
	ps->len = ps->len_a;
	ps->lvl = 1;
	ps->lvl_b = malloc(sizeof(int) * 1);
	if (!ps->lvl_b)
		error("malloc failure", 1);
	ps->lvl_b[0] = 0;
	return (0);
}

int	sort_algo(t_ps *ps)
{
	optimizer(ps);
	if (is_sorted(ps->a, ps->len_a) == 1)
		exit(0);
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
	int	a_init_size;

	i = -1;
	a_init_size = ps->len_a;
	b_init_size = ps->len_b;
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
	if (ps->len_b - b_init_size > 0 && ++ ps->lvl)
		add_one_num_front(ps, ps->len_b - b_init_size);
	divide_a_to_b(ps, a_init_size - ps->len_a + range % 2);
}

void	add_one_num_front(t_ps *ps, int data)
{
	int	i;
	int	*num_add;

	i = 1;
	num_add = malloc(sizeof(int) * (ps->lvl + 1));
	if (!num_add)
		error("malloc failure", 1);
	num_add[0] = data;
	while (i < ps->lvl + 1)
	{
		num_add[i] = ps->lvl_b[i - 1];
		i++;
	}
	free(ps->lvl_b);
	ps->lvl_b = num_add;
}

int	is_init(int *num, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (num[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

void	divide_b_to_a(t_ps *ps, int range)
{
	int	count;
	int	median;
	int	a_init_size;

	count = -1;
	a_init_size = ps->len_a;
	if (range <= 3 && -- ps->lvl)
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
	while (count-- > 0)
		rrb(ps);
	ps->lvl_b[0] = ps->lvl_b[0] - (ps->len_a - a_init_size);
	if (ps->len_a - a_init_size <= 3)
		sort_top_a(ps, ps->len_a - a_init_size);
	divide_a_to_b(ps, ps->len_a - a_init_size);
}
