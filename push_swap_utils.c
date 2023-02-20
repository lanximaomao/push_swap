#include "push_swap.h"

void error(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

void write_and_exit()
{
	write(1, "Error\n", 6);
	exit(1);
}

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
	ft_printf("My array is:  ");
	while (i < len)
	{
		ft_printf("%d  ", int_arr[i]);
		i++;
	}
	ft_printf("\n");
}
