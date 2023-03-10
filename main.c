/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/03/09 20:50:27 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ./push_swap 0 2 1 8 3 4 10  5 6 9  7
** ARG="1 8  12 13 14 15 20 16 18 19  17  4 5 2 9 6 10 3 11 0 7"; ./push_swap $ARG --> 93 steps
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

	ft_printf("\n\nmain function - after sorting: ");
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
		ft_printf("\na: ");
		ft_print_int_array(ps->a, ps->len_a);
		ft_printf("\nb: ");
		ft_print_int_array(ps->b, ps->len_b);
		ft_printf("\n");
		exit(0);
	}
	ps->len = ps->len_a;
	ps->lvl = 1;
	ps->lvl_b = malloc(sizeof(int) * 1);
	if (!ps->lvl_b)
		error("malloc failure", 1);
	ps->lvl_b[0] = 0;
	ft_printf("\n\n---------------------------------");
	ft_printf("\nstack a has %d numbers.\n", ps->len);
	ft_printf("---------------------------------\n\n");
	return(0);
}

/*
** there is always 3 numbers left in a;
*/

int sort_algo(t_ps *ps)
{

	optimizer(ps);

	first_divide_a_to_b(ps, ps->len_a);

	while (ps->lvl_b[0] != 0) // while level b is not zero
	{
		ft_printf("\n\n ********* loop through a chuck %d numbers!! **********\n\n", ps->lvl_b[0]);
		if (ps->len_b == 0 && ps->len == ps->len_a && is_sorted(ps->a, ps->len_a))
			break;
		if (ps->lvl_b[0] <= 3)
		{
			sort_top_b(ps, ps->lvl_b[0]);
			remove_one_num_front(ps);
			ps->lvl--;
		}
		else
			divide_b_to_a(ps, ps->lvl_b[0]);
		write(1, "\n", 1);
		write(1, "a: ",3);
		ft_print_int_array(ps->a, ps->len_a);
		write(1, "\nb: ",4);
		ft_print_int_array(ps->b, ps->len_b);
		write(1, "\n", 1);
		ft_printf("\n\n ********* finishing up loop **********\n\n");
	}
	return(0);
}

//include the sorting 	sort_small_a(ps);



int first_divide_a_to_b(t_ps *ps, int range)
{
	int i;
	int median;
	int b_init_size;
	int end_cpy;
	int end;

	i = 0;
	end = range -1;
	end_cpy = end;
	b_init_size = ps->len_b;

	if (ps->len_a <= 3)
	{
		sort_small_a(ps);
		return (1);
	}

	ft_printf("\n\n---------------------------------");
	ft_printf("\nmsg from divide_a_to_b:\n\n");
	write(1, "\n", 1);
	write(1, "a: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);


	median = find_median(ps->a, range);
	ft_printf("\nDivision is based on median value %d\n\n", median);

	while ( ps->len_b - b_init_size  < range / 2 )
	{
		if (ps->a[0] < median || (ps->a[0] == median && range %  2 == 0))
			pb(ps); // push to b
		else
		{
			ra(ps); // the first one become the last one
			i++;
		}
	}
	write(1, "\na: ", 4);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);

	i = 0;
	if( ps->len_b - b_init_size > 0)
	{
		add_one_num_front(ps, ps->len_b - b_init_size);
		ps->lvl++;
	}
	ft_printf("\n\n!!!! lvl_b array is: ");
	ft_print_int_array(ps->lvl_b, ps->lvl);
	ft_printf("\nsucessfully sent %d numbers to stack b\n", ps->len_b - b_init_size );
	ft_printf("---------------------------------\n\n");
	//divide_a_to_b(ps, ps->len_b - b_init_size);
	first_divide_a_to_b(ps, ps->len_a);
	return(0);
}


int divide_a_to_b(t_ps *ps, int range)
{
	int i;
	int median;
	int b_init_size;
	int a_init_size;
	//int end_cpy;
	//int end;

	i = 0;
	//end = range -1;
	//end_cpy = end;
	a_init_size = ps->len_a;
	b_init_size = ps->len_b;

	if (range <= 3)
	{
		sort_top_a(ps, range);
		return (1);
	}

	ft_printf("\n\n---------------------------------");
	ft_printf("\nmsg from divide_a_to_b:\n\n");
	write(1, "\n", 1);
	write(1, "a: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);


	median = find_median(ps->a, range);
	ft_printf("\nDivision is based on median value %d\n\n", median);

	while ( ps->len_b - b_init_size  < range / 2 )
	{
		if (ps->a[0] < median)
			pb(ps); // push to b
		else if (ps->a[0] == median && range %  2 == 0) // eg. a: 28 27 25 26
		{
			ft_printf("my range is %d and module is %d\n", range, range %2);
			pb(ps);
		}
		else if (ps->a[0] >= median)
		{
			ra(ps); // the first one become the last one
			i++;
		}
	}
	while (i > 0)
	{
		rra(ps);
		i--;
	}
	write(1, "\na: ", 4);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);

	i = 0;
	ft_printf("\nlen is %d\n", ps->lvl);

	ft_printf("ps->len_b - b_init_size is %d\n", ps->len_b - b_init_size);
	if( ps->len_b - b_init_size > 0)
	{
		add_one_num_front(ps, ps->len_b - b_init_size);
		ps->lvl++;
	}
	ft_printf("\n\n!!!! lvl_b array is: ");
	ft_print_int_array(ps->lvl_b, ps->lvl);
	ft_printf("\nsucessfully sent %d numbers to stack b\n", ps->len_b - b_init_size );
	ft_printf("---------------------------------\n\n");
	ft_printf("!!!------***** %d \n", ps->len_b - b_init_size);
	divide_a_to_b(ps, ps->len_a - a_init_size);//this is not right
	return(0);
}

void add_one_num_front(t_ps *ps, int data)
{
	int i;
	int *num_add;

	i = 1;
	num_add = malloc(sizeof(int) * (ps->lvl + 1)); // remember to free
	if (!num_add)
		error("malloc failure", 1);
	num_add[0] = data;
	while (i < ps->lvl + 1)
	{
		num_add[i] =  ps->lvl_b [i - 1];
		i++;
	}
	free(ps->lvl_b);
	ps->lvl_b = num_add;
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
int divide_b_to_a(t_ps *ps, int range)
{
	int i;
	int count;
	int median;
	int a_init_size;

	i = 0;
	count = 0;
	a_init_size = ps->len_a;



	//if less than three numbers, not need to divide
	if (range <= 3)
	{
		sort_top_b(ps, range);
		//remove this chuck from my lvl_b
		remove_one_num_front(ps);
		ps->lvl--;
		return (0);
	}

	ft_printf("\n\n---------------------------------");
	ft_printf("\nmsg from divide_b_to_a:");
	write(1, "\na: ",4);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);


	median = find_median(ps->b, range);
	ft_printf("\nDivision is based on median value %d\n\n", median);

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
	ps->lvl_b[0] = ps->lvl_b[0] - (ps->len_a - a_init_size);

	write(1, "\n", 1);
	write(1, "a: ",3);
	ft_print_int_array(ps->a, ps->len_a);
	write(1, "\nb: ",4);
	ft_print_int_array(ps->b, ps->len_b);
	write(1, "\n", 1);

	ft_printf("\nsucessfully sent %d numbers back to stack a\n", ps->len_a - a_init_size);
	ft_printf("---------------------------------\n\n");
	if (ps->len_a - a_init_size <= 3)
		sort_top_a(ps, ps->len_a - a_init_size);
	divide_a_to_b(ps, ps->len_a - a_init_size);
	return(0);
}

