#include "push_swap.h"



void	write_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_int(int **num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(num[i]);
		i++;
	}
	free(num);
}



int	find_max(int *num, int start, int end)
{
	int	max;

	max = num[start];
	while (start <= end)
	{
		if (num[start] > max)
			max = num[start];
		start++;
	}
	//ft_printf("my max is %d: \n", max);
	return (max);
}

int find_min(int *num, int start, int end)
{
	int min;

	min = num[start];
	while (start <= end )
	{
		if (num[start] < min)
			min = num[start];
		start++;
	}
	return(min);
}




void	error(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

void optimizer(t_ps *ps)
{
	int i;

	i = ps->len_a/2;
	while (i > 0)
	{
		if (ps->a[ps->len_a-i] == find_min(ps->a, 0, ps->len_a - 1))
			rra(ps);
		i--;
	}
	if (is_sorted(ps->a, ps->len) == 1)
		exit(0);
}

void optimizer_b(t_ps *ps)
{
	int i;

	i = ps->len_b/2;
	while (i > 0)
	{
		if (ps->b[ps->len_b-i] == find_max(ps->b, 0, ps->len_b - 1))
			rrb(ps);
		i--;
	}
}
