#include "push_swap.h"

void	error(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

void	write_and_exit(void)
{
	write(1, "Error\n", 6);
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
	ft_printf("\n");
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

int* int_arr_dup(int *num, int len)
{
	int i;
	int *int_dup;

	i = 0;
	int_dup = malloc(sizeof(int) * len);
	if (!int_dup)
		error("malloc fail", 1);
	while (i < len)
	{
		int_dup[i] = num[i];
		i++;
	}
	return(int_dup);
}

