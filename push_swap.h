#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_ps
{
	char** input;
	int *int_array;
	int len;
} t_ps;


void error(char *msg, int error_code);
void free_char(char **str);
void ft_print_int_array(int *int_arr, int len);

#endif
