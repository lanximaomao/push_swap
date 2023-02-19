#include "push_swap.h"


void free_char(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void free_int(int **num, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(num[i]);
		i++;
	}
	free(num);
}

void ft_print_int_array(int *int_arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d\n", int_arr[i]);
		i++;
	}
}