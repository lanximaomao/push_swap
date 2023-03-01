/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/03/01 22:14:06 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ./push_swap 0 2 1 8 3 4 10  5 6 9  7
** ARG="1 8  12 13 14 15 20 16 18 19  17  4 5 2 9 6 10 3 11 0 7"; ./push_swap $ARG
** ./push_swap  2 1 5  12 11 13 4 10 7 9 6 8 3 14 > out
** ./push_swap  2 1 5  12 11 13 4 10 7 9 6 8 3 > out
** tester: bash ../push_swap_tester/tester.sh ../push_swap 13 100
**
** fix this!
** ./push_swap 0 2147483647 9487 -2147483647 -2147483648  --> 13 moves
** ./push_swap 2147483647 9487 0 -2147483647 -2147483648 --> 13 moves
*/
# include "push_swap.h"

int main(int argc, char** argv)
{
	t_ps *ps;

	if (argc == 1)
		return(0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps_init(ps, argv); // error catch?

	sort_algo(ps);

	//ft_printf("main function - after sorting: ");
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_printf("\n");
	//ft_printf("my action count is now %d\n", ps->action_count);

	//free
	free(ps->a);
	free(ps->b);
	free(ps->lvl_b);
	free(ps);
	return(0);
}

int ps_init(t_ps *ps, char** argv)
{
	ps->input = argv + 1;
	check_for_length(ps);

	//one number
	if (ps->len_a <= 1)
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
	//ft_printf("\n\n---------------------------------");
	//ft_printf("\nstack a has %d numbers.\n", ps->len);
	//ft_printf("---------------------------------\n\n");
	level(ps);
	return(0);
}

int sort_algo(t_ps *ps)
{
	int start;
	int end;

	start = 0;
	end = ps->len_a - 1;
	optimizer(ps);
	divide_a_to_b(ps, start, end);
	//there is always 3 numbers left in a;
	sort_small_a(ps);
	add_back(ps);
	return(0);
}

// if the first num is big, put it in the end;
// if the last number is the min, put it at the beginning
void optimizer(t_ps *ps)
{
	if (ps->a[ps->len_a-1] == find_min(ps->a, 0, ps->len_a - 1))
	{
		rra(ps);
		//ft_printf("op after sorting: \n");
		//ft_print_int_array(ps->a, ps->len_a);
		//ft_printf("\n");
	}
	if (is_sorted(ps->a, ps->len) == 1)
	{
		//ft_printf("stack a is alreay sorted.");
		exit(0);
	}
}

//median value stays at a?
int divide_a_to_b(t_ps *ps, int start, int end)
{
	int i;
	int count;
	int median;
	int b_init_size;
	int range;

	i = 0;
	count = 0;
	b_init_size = ps->len_b;
	range = end - start + 1;
	if (range <= 3)
		return (0);
	median = find_median(ps->a, start, end);
	//ft_printf("\n\n---------------------------------");
	//ft_printf("\nmsg from divide_a_to_b:");
	//write(1, "\n", 1);
	//write(1, "a: ",3);
	//ft_print_int_array(ps->a, ps->len_a);
	//write(1, "b: ",3);
	//ft_print_int_array(ps->b, ps->len_b);
	//write(1, "\n", 1);
	//ft_printf("\nDivision is based on median value %d\n\n", median);
	//as long as median is not the smallest in the stack, we have got something to push
	//this will also keep the median value itself inside my stack a
	while ( ps->len_b - b_init_size  < range / 2 )
	{
		if (ps->a[0] < median || (ps->a[0] == median && range %  2 == 0))
		{
			pb(ps); // push to b
			//write(1, "\n", 1);
			//write(1, "a: ",3);
			//ft_print_int_array(ps->a, ps->len_a);
			//write(1, "\n", 1);
			//write(1, "b: ",3);
			//ft_print_int_array(ps->b, ps->len_b);
			//write(1, "\n\n", 1);
			end--;
		}
		else
		{
			ra(ps); // the first one become the last one
			//write(1, "\n", 1);
			//write(1, "a: ",3);
			//ft_print_int_array(ps->a, ps->len_a);
			//write(1, "\n", 1);
			//write(1, "b: ",3);
			//ft_print_int_array(ps->b, ps->len_b);
			//write(1, "\n", 1);
			count++;
		}
	}
	while (count > 0)
	{
		rra(ps);
		//write(1, "\n", 1);
		//write(1, "a: ",3);
		//ft_print_int_array(ps->a, ps->len_a);
		//write(1, "b: ",3);
		//ft_print_int_array(ps->b, ps->len_b);
		//write(1, "\n", 1);
		count--;
	}
	//write(1, "\n", 1);
	//write(1, "a: ",3);
	//ft_print_int_array(ps->a, ps->len_a);
	//write(1, "b: ",3);
	//ft_print_int_array(ps->b, ps->len_b);
	//write(1, "\n", 1);
	//ft_printf("send %d numbers to stack b\n", ps->len_b - b_init_size );
	//ft_printf("---------------------------------\n\n");
	divide_a_to_b(ps, 0, ps->len_a- 1);
	return(ps->len_b - b_init_size);
}

//differ than divide_a_to_b, this is not a recursive function
int divide_b_to_a(t_ps *ps, int start, int end)
{
	int i;
	int count;
	int median;
	int a_init_size;
	int range;

	i = 0;
	count = 0;
	//if less than three numbers, not need to divide
	range = end - start + 1;
	if (range <= 3)
		return (0);
	median = find_median(ps->b, start, end);
	//ft_printf("\n\n---------------------------------");
	//ft_printf("\nmsg from divide_b_to_a:");
	//write(1, "\n", 1);
	//write(1, "a: ",3);
	//ft_print_int_array(ps->a, ps->len_a);
	//write(1, "b: ",3);
	//ft_print_int_array(ps->b, ps->len_b);
	//write(1, "\n", 1);
	//ft_printf("\nDivision is based on median value %d\n\n", median);
	a_init_size = ps->len_a;
	//as long as the median is not the biggest, you will always have something to push from b to a
	// how about medium value?
	while (ps->len_a - a_init_size <  range / 2)
	{
		if (ps->b[0] > median || (ps->b[0] > median && range % 2 == 0 ))
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
	//write(1, "\n", 1);
	//write(1, "a: ",3);
	//ft_print_int_array(ps->a, ps->len_a);
	//write(1, "b: ",3);
	//ft_print_int_array(ps->b, ps->len_b);
	//write(1, "\n", 1);
	//ft_printf("send %d numbers to stack a\n", ps->len_a - a_init_size);
	//ft_printf("---------------------------------\n\n");
	return(ps->len_a - a_init_size);
}

//loop through each section of b
int add_back(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->lvl)
	{
		//ft_printf("\n\n---------------------------------");
		//ft_printf("\nstart to add back process: ");
		//ft_printf("loop %d with %d numbers.\n", i, ps->lvl_b[ps->lvl - 1 - i]);
		throw_and_catch(ps, 0, ps->lvl_b[ps->lvl - 1 - i]-1);
		//write(1, "\n", 1);
		//write(1, "a: ",3);
		//ft_print_int_array(ps->a, ps->len_a);
		//write(1, "b: ",3);
		//ft_print_int_array(ps->b, ps->len_b);
		//write(1, "\n", 1);
		//ft_printf("---------------------------------\n\n");
		i++;
	}
	return(0);
}

//this will be recursive

void throw_and_catch(t_ps *ps, int start, int end)
{
	int range;
	int ret;

	range = end - start + 1;
	if (range < 1)
		return;
	if (range == 2 || range == 3) // 2 nums
	{
		push_less_than_three_b_to_a(ps, range);
		return;
	}
	ret = divide_b_to_a(ps, start, end); // at least 4 nums

	//this part is problemetic!!
	//if (ret > 3)
	//{
	//	write(1, "\nTTTTT\n", 7);
	//	divide_a_to_b(ps, 0, ps->len_b - 1);
	//	write(1, "\nTTTTT\n", 7);
	//}

	sort_top_three_a(ps);
	push_less_than_three_b_to_a(ps, ps->len_b);
	//throw_and_catch(ps, 0, range - 3);//not optimal
}
