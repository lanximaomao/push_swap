/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/03/02 15:25:43 by lsun             ###   ########.fr       */
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
** -160503775 1032067362 394109596 -465545840 -478337097 --> 13 moves
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
	ft_printf("\nsucessfully sent %d numbers to stack b\n", ps->len_b - b_init_size );
	ft_printf("---------------------------------\n\n");
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
		ft_printf("loop %d with %d numbers.\n", i, ps->lvl_b[ps->lvl - 1 - i]);
		write(1, "\na: ",4);
		ft_print_int_array(ps->a, ps->len_a);
		write(1, "\nb: ",4);
		ft_print_int_array(ps->b, ps->len_b);
		write(1, "\n\n", 2);
		throw_and_catch(ps, 0, ps->lvl_b[ps->lvl - 1 - i]-1);
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

int *sub_level_b(t_ps *ps)
{
	int i;
	int *b_sub_lvl;

	i = 0;
	b_sub_lvl = malloc(sizeof(int) * ps->lvl);
	if (!b_sub_lvl)
		error("malloc fail", 1);
	while (i < ps->lvl)
	{
		b_sub_lvl[i] = 0;
		i++;
	}
	return(b_sub_lvl);
}

void throw_and_catch(t_ps *ps, int start, int end)
{
	int i;
	int range;
	int ret;
	int *b_sub;
	//int left_over;

	i = 0;
	ret = 4;
	range = end - start + 1;
	if (range < 1)
		return;
	if (range == 2 || range == 3) // 2 nums
	{
		push_less_than_five_b_to_a(ps, range);
		return;
	}
	//this part is problemetic!!
	b_sub = sub_level_b(ps);
	if (!b_sub)
		error("malloc fail", 1);
	while (ret > 3)
	{
		ft_printf("************ Epic loop starts ************");
		ret = divide_b_to_a(ps, start, end); // at least 4 nums
		ft_printf("\nnew ret is %d: \n", ret);
		if (ret <= 3)
		{
			sort_top_three_a(ps);
			//left_over = ps->lvl_b[ps->lvl - 1 - i] - ret;
			////fetch the leftover from the last division
			//push_less_than_five_b_to_a(ps, left_over);
			push_less_than_five_b_to_a(ps, ps->len_b);
			return;
		}
		ft_printf("my b len is %d\n", ps->len_b);
		if (ps->len_b <= 5)
		{
			push_less_than_five_b_to_a(ps, ps->len_b);
		}

		if (ret > 3)
		{
			b_sub[i] = divide_a_to_b(ps, 0, ret - 1);
			i++;
		}
		ft_printf("************ Epic loop ends ************");
		// if (b_sub[i])
	}


	//throw_and_catch(ps, 0, range - 3);//not optimal
}
