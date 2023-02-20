#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack
{
	int num;
	int index;
	struct s_stack *next;
} t_stack;

typedef struct s_ps
{
	char** input;
	int *int_array;
	int len;
	t_stack a;
	t_stack b;
} t_ps;

void error(char *msg, int error_code);
void write_and_exit();
void free_char(char **str);
void free_int(int **num, int size);
void ft_print_int_array(int *int_arr, int len);

//is_valid

t_ps* is_uniq(t_ps *ps);
t_ps* check_for_length(t_ps *ps);
t_ps* parsing(t_ps *ps);


//actions
void create_stack(t_ps *ps);

#endif
