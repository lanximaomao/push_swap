/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/02/26 20:03:34 by linlinsun        ###   ########.fr       */
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
	ft_printf("\nstack a has %d numbers.\n\n", ps->len);
	return(0);
}
//median value stays at a

void divide_algo_a(t_ps *ps, int start, int end)
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
	write(1, "\na: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "b: ",3);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);
	divide_algo_a(ps, start, ps->len_a - 1);
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
	while (median != find_max(ps->b, ps->len_b))
	{
		if (ps->b[0] > median)
			pa(ps); // push to a
		else
			rb(ps); // the first one become the last one
	}
	//write(1, "\na: ",3);
	//ft_print_int_array(ps->a, ps->len_a);
	//write(1, "b: ",3);
	//ft_print_int_array(ps->b, ps->len_b);
	//write(1, "\n", 1);
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

int level(int len)
{
	int i;

	i = 1;
	while (len / 2 + len % 2 > 3)
	{
		len = len / 2  + len % 2;
		i++;
	}
	len = len / 2;
	ft_printf("\nlast level is %d. \n", i);
	ft_printf("\nmy last level len is now %d\n\n", len);
	return(len);
}

//this will be recursive
//
int add_back(t_ps *ps)
{

	if (ps->len_b <= 3)
	{
		sort_small_b(ps);
		if (ps->len_a == ps->len)
		{
			ft_printf("a: ");
			ft_print_int_array(ps->a, ps->len_a);
			ft_printf("b: ");
			ft_print_int_array(ps->b, ps->len_b);
			exit(1);
		}
	}
	//check the top chuck, which is always 2-3 nums
	if (level(ps->len) == 2)
		push_two_b(ps);
	else if (level(ps->len == 3))
		push_three_b(ps);
	if (ps->len_b > 3)
	{
		divide_algo_b(ps, 0, 3);//?
	}
	add_back(ps);

	// or sort_three_b(ps), 11 number will get b at 3+5


	//dive b and push to a the smaller half
	//divide_algo_b(ps, 0, 1);
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
