/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/03/03 17:59:58 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ./push_swap 0 2 1 8 3 4 10  5 6 9  7
** ARG="1 8  12 13 14 15 20 16 18 19  17  4 5 2 9 6 10 3 11 0 7"; ./push_swap $ARG
** ./push_swap  2 1 5  12 11 13 4 10 7 9 6 8 3 14 > out
** ./push_swap  2 1 5  12 11 13 4 10 7 9 6 8 3 > out
**  ./push_swap  2 1 5  12 21 11 22 19 13 20 23 4 18 17 15 16 10 30 7 28 9 27 29 6 26 8 3 25 24  14 > out
** tester: bash ../push_swap_tester/tester.sh ../push_swap 13 100
**
** fix this!
** ./push_swap 0 2147483647 9487 -2147483647 -2147483648  --> 13 moves
** ./push_swap 2147483647 9487 0 -2147483647 -2147483648 --> 13 moves
** -160503775 1032067362 394109596 -465545840 -478337097 --> 13 moves
**
**
./push_swap  2 1 5  12 21 11 22 19 13 20 23 4 18 17 15 16 10 30 7 28 9 27 29 6 26 8 3 25 24  14 > out
*/

# include "push_swap.h"

int main(int argc, char** argv)
{
	t_ps *ps;

	ft_printf("hello world !!!!\n");
	if (argc == 1)
		return(0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps_init(ps, argv); // error catch?

	sort_algo(ps);

	ft_printf("main function - after sorting: ");
	ft_printf("\na: ");
	ft_print_int_array(ps->a, ps->len_a);
	ft_printf("\nb: ");
	ft_print_int_array(ps->b, ps->len_b);
	ft_printf("\n");
	ft_printf("my action count is now %d\n", ps->action_count);

	free(ps->a);
	free(ps->b);
	free(ps->lvl_b);
	free(ps);

	//ft_printf("%d\n", sizeof(ps1)*1);
	//ft_printf("%d\n", sizeof(*ps1));

	return(0);
}

int ps_init(t_ps *ps, char** argv)
{
	ps->input = argv + 1;
	check_for_length(ps);

	if (ps->len_a <= 1)
		exit(0);
	ps->a = malloc(sizeof(int)*ps->len_a);
	ps->b = malloc(sizeof(int)*ps->len_a);
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
	ft_printf("\n\n---------------------------------");
	ft_printf("\nstack a has %d numbers.\n", ps->len);
	ft_printf("---------------------------------\n\n");
	level(ps);
	return(0);
}

/*
** there is always 3 numbers left in a;
*/

int sort_algo(t_ps *ps)
{
	int start;
	int end;

	start = 0;
	end = ps->len_a - 1;
	optimizer(ps);
	divide_a_to_b(ps, start, end);
	sort_small_a(ps);
	add_back(ps);
	return(0);
}

/*
** median value stays at a?
*/

int divide_a_to_b(t_ps *ps, int start, int end)
{
	int i;
	int j;
	int count;
	int median;
	int b_init_size;
	int range;
	int end_cpy;

	i = 0;
	j = 0;
	count = 0;
	end_cpy = end;
	b_init_size = ps->len_b;
	range = end - start + 1;
	if (range <= 3)
		return (0);
	median = find_median(ps->a, start, end);
	ft_printf("\n\n---------------------------------");
	ft_printf("\nmsg from divide_a_to_b:");
	write(1, "\n", 1);
	write(1, "a: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",3);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);
	ft_printf("\nDivision is based on median value %d\n\n", median);
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
	write(1, "\na: ", 4);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);
	//assign the value if it is not zero

	if (is_init(ps->lvl_b, ps->lvl + 2) == 0)
		ps->lvl_b[ps->lvl-1] = ps->len_b - b_init_size;
	else
	{
		while (ps->lvl_b[ps->lvl - 1- j] != 0)
		{
			j++;
		}
		ps->lvl_b[ps->lvl - 1- j] = ps->len_b - b_init_size;
	}
	ft_printf("\n\n!!!!lvl_b is %d\n", ps->lvl_b[ps->lvl - 1- j]);
	ft_printf("\nsucessfully sent %d numbers to stack b\n", ps->len_b - b_init_size );
	ft_printf("---------------------------------\n\n");
	divide_a_to_b(ps, 0, end_cpy / 2);
	return(ps->len_b - b_init_size);
}

int is_init(int *num, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (num[i] != 0)
			return (1); //not in init status
		i++;
	}
	return(0); // is in init status
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
	ft_printf("\n\n---------------------------------");
	ft_printf("\nmsg from divide_b_to_a:");
	write(1, "\na: ",4);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);
	ft_printf("\nDivision is based on median value %d\n\n", median);
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
	write(1, "\n", 1);
	write(1, "a: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);
	ft_printf("\nsucessfully sent %d numbers back to stack a\n", ps->len_a - a_init_size);
	ft_printf("---------------------------------\n\n");
	return(ps->len_a - a_init_size);
}

//loop through each section of b
int add_back(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->lvl)
	{
		ft_printf("\n\n---------------------------------");
		ft_printf("\nstart to add back process: ");
		ft_printf("loop %d with %d numbers.\n", i, ps->lvl_a[ps->lvl - 1 - i]);
		write(1, "\na: ",4);
		ft_print_int_array(ps->a, ps->len_a);
		write(1, "\nb: ",4);
		ft_print_int_array(ps->b, ps->len_b);
		write(1, "\n\n", 2);
		throw_and_catch(ps, 0, ps->lvl_a[ps->lvl - 1 - i]-1);
		write(1, "\na: ",4);
		ft_print_int_array(ps->a, ps->len_a);
		write(1, "\nb: ",4);
		ft_print_int_array(ps->b, ps->len_b);
		write(1, "\n", 1);
		ft_printf("---------------------------------\n\n");
		i++;
	}
	return(0);
}

//this will be recursive

void level_b_init(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->lvl + 2)
	{
		ps->lvl_b[i] = 0;
		i++;
	}
}

void throw_and_catch(t_ps *ps, int start, int end)
{
	int i;
	int j;
	int range;
	int ret;
	int left_over;

	i = 0;
	j = 0;
	range = end - start + 1;
	if (range < 1)
		return;
	if (range == 2 || range == 3) // 2 nums
	{
		push_less_than_five_b_to_a(ps, range);
		return;
	}
	left_over = 1;
	//this part is problemetic!!
	while (left_over > 0)
	{
		ft_printf("\n************ Epic loop starts ************\n");
		ret = divide_b_to_a(ps, start, end); // at least 4 nums
		left_over = end - ret + 1;
		ft_printf("\nnew ret is %d: \n", ret);
		ft_printf("leftover is %d\n", left_over);
		if (ret <= 3)
		{
			sort_top_three_a(ps);
			if (left_over <= 3)
			{
				push_n_and_sort_a(ps, left_over);//!!
				return;
			}
			if (left_over > 3)
			{
				start = 0;
				end = left_over  - 1;
			}
		}
		// ret = 7 and leftover = 8
		if (ret >= 4)
		{
		//	reset lvl_b
			ft_printf("\n\nbefor level b init: ");
			ft_printf("\nlvl is %d\n", ps->lvl);
			ft_print_int_array(ps->lvl_b, ps->lvl + 2);
			ft_printf("\n\n");
			level_b_init(ps);
			ft_printf("\nafter level b init: ");
			ft_print_int_array(ps->lvl_b, ps->lvl + 2);
			ft_printf("\n\n");
			divide_a_to_b(ps, 0, ret - 1);
			ft_printf("\nafter divide a  to b, level b init: \n");
			ft_print_int_array(ps->lvl_b, ps->lvl + 2);
			ft_printf("\n\n");
			//save left over

			ps->lvl_b[ps->lvl] = left_over;
			ft_printf("after saving my leftover %d, my b level becomes\n", left_over);
			ft_print_int_array(ps->lvl_b, ps->lvl + 2);
			ft_printf("\n\n");

			//after this, b will have the leftover + whatever is given by a, saved at ps->lvl_b
			sort_top_three_a(ps);
			j = 0;
			while (ps->lvl_b[j] == 0 && j < ps->lvl + 2 )
			{
				j++;
			}
			while (ps->lvl_b[j] != 0) // continue with the loop by reset the ending point
			{
				if (ps->lvl_b[j] <= 3)
				{
					push_n_and_sort_a(ps, ps->lvl_b[j]);
					write(1, "\na: ",4);
					ft_print_int_array(ps->a, ps->len_a);
					write(1, "\nb: ",4);
					ft_print_int_array(ps->b, ps->len_b);
					write(1, "\n\n", 2);
					ft_printf("i am here!!\n");
				}
				j++;
				ft_printf("my leftover is the same %d\n", left_over);
				ft_printf("\n and it is showing here %d\n", ps->lvl_b[j - 1]);
			}
			end = ps->lvl_b[j - 1] - 1;
			ft_printf("my new end is now %d\n", end);
		}
	}
		ft_printf("\n************ Epic loop ends ************\n");
}


	//throw_and_catch(ps, 0, range - 3);//not optimal

void push_n_and_sort_a(t_ps *ps, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		pa(ps);
		i++;
	}
	sort_top_three_a(ps);
}
