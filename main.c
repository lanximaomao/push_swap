
# include "push_swap.h"

int main(int argc, char** argv)
{
	t_ps *ps;

	if (argc == 1)
		return(0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps->input = argv + 1;
	check_for_length(ps);
	//ft_printf("len is %d\n", ps->len_a);
	ps->a = malloc(sizeof(int)*ps->len_a);
	ps->b = malloc(sizeof(int)*ps->len_a);
	ps->len_b = 0;
	if (!ps->a || !ps->b)
		error("malloc fail", 1);
	//
	is_uniq(parsing(ps));
	ft_print_int_array(ps->a, ps->len_a);
	pb(ps);
	pb(ps);
	pb(ps);
	rrr(ps);
	ft_print_int_array(ps->a, ps->len_a);
	ft_print_int_array(ps->b, ps->len_b);
	//rb(ps);
	//ft_print_int_array(ps->a, ps->len_a);
	//ft_print_int_array(ps->b, ps->len_b);
	//free
	free(ps->a);
	free(ps);
	return(0);
}
