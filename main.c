/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/02/24 19:18:16 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ./push_swap 0 2 1 8 3 4 10  5 6 9  7
*/
# include "push_swap.h"

int ps_init(t_ps *ps, char** argv)
{
	ps->input = argv + 1;
	check_for_length(ps);
	//ft_printf("len is %d\n", ps->len_a);
	ps->a = malloc(sizeof(int)*ps->len_a);
	ps->b = malloc(sizeof(int)*ps->len_a);
	ps->len_b = 0;
	if (!ps->a || !ps->b)
		error("malloc fail", 1);
	is_uniq(parsing(ps));
	ps->action_count = 0;
	ft_printf("original len a is %d\n", ps->len_a);
	return(0);
}
//median value stays at a

void divide_algo(t_ps *ps, int start, int end)
{
	int i;
	int count;
	int median;

	i = 0;
	count = 0;
	if (ps->len_a < 4)
		return;
	median = find_median(ps->a, start, end);
	while (median != find_min(ps->a, ps->len_a))
	{
		if (ps->a[0] < median)
			pb(ps); // push to b
		else
			ra(ps); // the first one become the last one
	}
	write(1, "a: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "b: ",3);
	ft_print_int_array(ps->b, ps->len_b);
	divide_algo(ps, start, ps->len_a - 1);
}

//possibe to expand the same logic
void optimizer(t_ps *ps)
{
	if (ps->a[0] == find_max(ps->a, ps->len_a) || ps->a[ps->len_a-1] == find_min(ps->a, ps->len_a))
		rra(ps); // if the first num is big, put it
}

void sort_algo(t_ps *ps)
{
	int start;
	int end;

	start = 0;
	end = ps->len_a - 1;
	//count = 0;
	//while (ps->len_a > 3)
	//{
	//	divide_algo(ps, start-count, end);
	//}
	optimizer(ps);
	divide_algo(ps, start, end);
	sort_small_a(ps);
	add_back(ps);

	//check out final result
	ft_printf("\n---- sorted stack a ----\n");
	ft_print_int_array(ps->a, ps->len_a);
}

void add_back(t_ps *ps)
{
	if (ps->len_b <= 3)
		sort_small_b(ps);
}

int ps_in_action(t_ps *ps)
{
	if (ps->len_a <= 3)
		sort_small_a(ps);
	sort_algo(ps);
	//ft_printf("a: ");
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_printf("b: ");
	//ft_print_int_array(ps->b, ps->len_b);
	return(0);
}

int main(int argc, char** argv)
{
	t_ps *ps;

	if (argc == 1)
		return(0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps_init(ps, argv); // error catch?
	ps_in_action(ps);
	// find midian
	//ft_printf("before sorting: ");
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_printf("median value is %d: ", find_median(ps->a, 0, ps->len_a - 1));

	//count
	ft_printf("my action count is now %d\n", ps->action_count);

	//free
	free(ps->a);
	free(ps);
	return(0);
}
