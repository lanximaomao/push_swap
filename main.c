
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
	return(0);
}

void sort_two_a(t_ps *ps)
{
	if(ps->a[0] < ps->a[1])
		return;
	sa(ps);
}

void sort_two_b(t_ps *ps)
{
	if(ps->b[0] < ps->b[1])
		return;
	sb(ps);
}

void sort_three_a(t_ps *ps)
{
	if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
		ra(ps);
	else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
		rra(ps);
	if (ps->a[0] > ps->a[1])
		sa(ps);
}

void sort_three_b(t_ps *ps)
{
	if (ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2])
		ra(ps);
	else if (ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
		rra(ps);
	if (ps->b[0] > ps->b[1])
		sa(ps);
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
	ft_printf("my median is %d \n", median);
	while (median < find_max(ps->a, ps->len_a))
	{
		if (ps->a[0] > median)
			pb(ps); // push to b
		else
			ra(ps); // the first one become the last one
	}
}

void sort_more(t_ps *ps)
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
	divide_algo(ps, start, end);
}

int ps_in_action(t_ps *ps)
{
	if (ps->len_a == 1)
		exit(0);
	if (ps->len_a == 2)
	{
		sort_two_a(ps);
		ft_printf("after sorting: ");
		ft_print_int_array(ps->a, ps->len_a);
		exit(0);
	}
	if (ps->len_a == 3)
	{
		sort_three_a(ps);
		ft_printf("after sorting: ");
		ft_print_int_array(ps->a, ps->len_a);
		exit(0);
	}
	if (ps->len_a >= 4)
	{
		sort_more(ps);
		ft_printf("a: ");
		ft_print_int_array(ps->a, ps->len_a);
		ft_printf("b: ");
		ft_print_int_array(ps->b, ps->len_b);
	}

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
	//free
	free(ps->a);
	free(ps);
	return(0);
}

// action

	//ft_print_int_array(ps->a, ps->len_a);
	//pb(ps);
	//pb(ps);
	//pb(ps);
	//rrr(ps);
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_print_int_array(ps->b, ps->len_b);
	//rb(ps);
	//ft_print_int_array(ps->a, ps->len_a);
