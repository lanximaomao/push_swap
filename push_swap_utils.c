#include "push_swap.h"

void	error(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

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

void	ft_print_int_array(int *int_arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d  ", int_arr[i]);
		i++;
	}
	//ft_printf("\n");
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
	ft_printf("\n\n---------------------------------");
	ft_printf("\nlvl in b is %d\n", ps->lvl);
	ps->lvl_a = malloc(sizeof(int) * ps->lvl);
	if (!ps->lvl_a)
		error("malloc fail", 1);
	tmp = ps->len;
	while (tmp > 3)
	{
		ps->lvl_a[i] = tmp/2;
		ft_printf("level %d is has %d numbers\n", i, ps->lvl_a[i]);
		tmp = tmp / 2 + tmp % 2;
		i++;
	}
	ft_printf("---------------------------------\n\n");
	ps->lvl_b = malloc(sizeof(int) * ps->lvl);
	if (!ps->lvl_b)
		error("malloc fail", 1);
}

int is_sorted(int *num, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (num[i] > num[i + 1])
			return(0);
		i++;
	}
	return(1);
}
