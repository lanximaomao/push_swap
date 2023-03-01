/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/03/01 15:02:12 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ./push_swap 0 2 1 8 3 4 10  5 6 9  7
** ARG="1 8  12 13 14 15 20 16 18 19  17  4 5 2 9 6 10 3 11 0 7"; ./push_swap $ARG
*/
# include "push_swap.h"

int ps_init(t_ps *ps, char** argv)
{
	ps->input = argv + 1;
	check_for_length(ps);

	//one number
	if (ps->len_a == 1)
		exit(0);
	//ft_printf("len is %d\n", ps->len_a);
	ps->a = malloc(sizeof(int)*ps->len_a);
	ps->b = malloc(sizeof(int)*ps->len_a);
	ps->len_b = 0;
	if (!ps->a || !ps->b)
		error("malloc fail", 1);
	is_uniq(parsing(ps));
	ps->action_count = 0;
	if (ps->len_a <= 3)
	{
		sort_small_a(ps);
		exit(0);
	}
	ps->len = ps->len_a;
	//ft_printf("\nstack a has %d numbers.\n\n", ps->len);
	//level(ps);
	return(0);
}
//median value stays at a

void divide_algo_a(t_ps *ps, int start, int end)
{
	int i;
	int count;
	int median;
	int len;

	i = 0;
	count = 0;
	len = ps->len_a;
	if (end - start < 3)
		return;
	median = find_median(ps->a, start, end);

	while (median != find_min(ps->a, start, end))
	{
		ft_printf("median is %d\n", median);
		ft_printf("min is %d\n", find_min(ps->a, start, end));
		if (ps->a[0] < median)
			pb(ps); // push to b
		else
		{
			ra(ps); // the first one become the last one
			count++;
		}
	}
	while (count > 0)
	{
		rra(ps);
		count--;
	}
	write(1, "\na: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "b: ",3);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);
	//!! recursive condition is wrong
	divide_algo_a(ps, 0, len - ps->len_a);

}

//differ than divide_algo_a, this is not a recursive function
void divide_algo_b(t_ps *ps, int start, int end)
{
	int i;
	int count;
	int median;

	i = 0;
	count = 0;
	median = find_median(ps->b, start, end);
	ft_printf("my median is %d\n", median);
	while (median != find_max(ps->b, start, end))
	{
		ft_printf("my max is %d\n", find_max(ps->b, start, end));
		if (ps->b[0] > median)
			pa(ps); // push to a
		else
		{
			rb(ps); // the first one become the last one
			count++;
		}
	}
	while (count > 0)
	{
		rrb(ps);
		count--;
	}

	//write(1, "\na: ",3);
	//ft_print_int_array(ps->a, ps->len_a);
	//write(1, "b: ",3);
	//ft_print_int_array(ps->b, ps->len_b);
	//write(1, "\n", 1);
	ft_printf("divide algo a: ");
	ft_print_int_array(ps->a, ps->len_a);
	ft_printf("divide algo b: ");
	ft_print_int_array(ps->b, ps->len_b);
}

//possibe to expand the same logic
void optimizer(t_ps *ps)
{
	if (ps->a[0] == find_max(ps->a, 0, ps->len_a) || ps->a[ps->len_a-1] == find_min(ps->a, 0, ps->len_a))
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
	divide_algo_a(ps, start, end);
	sort_small_a(ps);

	//check out final result
}

int ps_in_action(t_ps *ps)
{
	if (ps->len_a <= 3)
		sort_small_a(ps);
	sort_algo(ps);
	add_back(ps);
	ft_printf("a: ");
	ft_print_int_array(ps->a, ps->len_a);
	ft_printf("b: ");
	ft_print_int_array(ps->b, ps->len_b);
	return(0);
}

void level(t_ps *ps)
{
	int	i;
	int tmp;

	i = 0;
	ps->lvl = 0;
	tmp = ps->len;;
	while (tmp > 3)
	{
		tmp = tmp / 2 + tmp % 2;
		ps->lvl++;
	}
	ft_printf("lvl in b is %d\n", ps->lvl);
	ps->lvl_b = malloc(sizeof(int) * ps->lvl);//free
	if (!ps->lvl_b)
		error("malloc fail", 1);
	tmp = ps->len;
	while (tmp > 3)
	{
		ps->lvl_b[i] = tmp/2;
		ft_printf("level %d is has %d numbers\n", i, ps->lvl_b[i]);
		tmp = tmp / 2 + tmp % 2;
		i++;
	}
}


//this will be recursive

void throw_and_catch(t_ps *ps, int start, int end)
{
	int range;

	range = end - start + 1;
	if (range < 1)
		return;
	if (range == 2) // 2 nums
	{
		push_two_b(ps);
		return;
	}
	if (range == 3)// 3 nums
	{
		push_three_b(ps);
		return;
	}
	divide_algo_b(ps, start, end); // at least 4 nums
	if (range/2 + range % 2 > 3)
	{
		divide_algo_a(ps, 0, range/2 + range % 2);
		write(1, "TTTTT\n", 6);
	}
	// so far the code looks good until here!!!

	sort_top_three_a(ps);
	push_three_b(ps);
	write(1, "here\n", 5);
	//throw_and_catch(ps, 0, range - 3);//not optimal
}

int add_back(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->lvl)
	{
		write(1, "\n\n!loop!\n\n", 9);
		ft_printf("lvl is %d\n", ps->lvl);
		ft_printf("end %d\n", ps->lvl_b[ps->lvl - 1 - i]);
		throw_and_catch(ps, 0, ps->lvl_b[ps->lvl - 1 - i]-1);
		ft_printf("a after loop: ");
		ft_print_int_array(ps->a, ps->len_a);
		ft_printf("b after loop: ");
		ft_print_int_array(ps->b, ps->len_b);
		i++;
	}
	return(0);
}
//
//int add_back(t_ps *ps)
//{
//	int i;
//	int leftover;

//	if (ps->len_b <= 3)
//	{
//		sort_small_b(ps);
//		if (ps->len_a == ps->len)
//		{
//			ft_printf("a: ");
//			ft_print_int_array(ps->a, ps->len_a);
//			ft_printf("b: ");
//			ft_print_int_array(ps->b, ps->len_b);
//			exit(1);
//		}
//	}
//	//check the top chuck, which is always 2-3 nums
//	if (ps->lvl_b[ps->lvl - 1] == 2)
//		push_two_b(ps);
//	else if (ps->lvl_b[ps->lvl - 1] == 3)
//		push_three_b(ps);
//	//
//	//	loop through different level of b
//	//
//	i = 2;
//	while (ps->len_b > 3 && i < ps->lvl - 1)
//	{
//		divide_algo_b(ps, 0, ps->lvl_b[ps->lvl - i]);
//		if (ps->lvl_b[ps->lvl - i] > 3)
//		{
//			//threw everything but the biggest three in a
//			divide_algo_a(ps, 0, ps->lvl_b[ps->lvl - i]/2 + ps->lvl_b[ps->lvl - i] % 2);
//			// sort the top three at a
//			sort_top_three_a(ps);
//			//what is the leftover at b
//			leftover = ps->lvl_b[ps->lvl - i] - 3;
//			if (leftover == 2)
//				push_two_b(ps);
//			if (leftover == 3)
//				push_three_b(ps); // not test?
//			if (leftover > 3)
//				add_back(ps);
//		}
//		i++;
//	}
//	// or sort_three_b(ps), 11 number will get b at 3+5
//	//dive b and push to a the smaller half
//	//divide_algo_b(ps, 0, 1);
//	return(0);
//}

void my_lazy_sort(t_ps *ps, int *index_arr)
{
	int i;
	i = 0;

	ps->a = index_arr;

	while (ps->len_a != 0 && i < ps->len)
	{
		while (index_arr[0] != i + 1)
		{
			ra(ps);
		}
		pb(ps);
		i++;
	}
	i = 0;
	while ( i < ps->len)
	{
		pa(ps);
		i++;
	}
}

int main(int argc, char** argv)
{
	t_ps *ps;
	int * num_dup;
	int *index_arr;

	if (argc == 1)
		return(0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps_init(ps, argv); // error catch?

	num_dup = bubble_sort(ps->a, 0, ps->len_a - 1);
	//ft_printf("num_dup: ");
	//ft_print_int_array(num_dup, ps->len_a);
	index_arr = index_num(ps->a, num_dup, ps->len_a);
	my_lazy_sort(ps, index_arr);

	//ps_in_action(ps);
	// find midian
	//ft_printf("before sorting: ");
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_printf("median value is %d: ", find_median(ps->a, 0, ps->len_a - 1));

	//count
	//ft_printf("my action count is now %d\n", ps->action_count);

	//free
	free(ps->a);
	free(ps);
	return(0);
}
