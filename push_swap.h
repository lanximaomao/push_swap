#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_ps
{
	char	**input;
	int		*a;
	int		*b;
	int		len;
	int		len_a;
	int		len_b;
	int		lvl;
	int*	lvl_a;
	int* 	lvl_b;
	int		action_count;
}			t_ps;


void		error(char *msg, int error_code);
void		write_and_exit(void);
void		free_char(char **str);
void		free_int(int **num, int size);
void		ft_print_int_array(int *int_arr, int len);

//is_valid

t_ps		*is_uniq(t_ps *ps);
t_ps		*check_for_length(t_ps *ps);
t_ps		*parsing(t_ps *ps);

//actions
void		sa(t_ps *ps);
void		sb(t_ps *ps);
void		ss(t_ps *ps);
void		pa(t_ps *ps);
void		pb(t_ps *ps);
void		ra(t_ps *ps);
void		rb(t_ps *ps);
void		rr(t_ps *ps);
void		rra(t_ps *ps);
void		rrb(t_ps *ps);
void		rrr(t_ps *ps);

//sort
int is_sorted(int *num, int len);
int* bubble_sort(int *num, int start, int end);
void		quick_sort(int *num, int start, int end);
int			parition(int *num, int start, int end);
void		ft_swap(int i, int j);


//utils
int* int_arr_dup(int *num, int len);
int	find_median(int *num, int start, int end);
int	find_max(int *num, int start, int end);
int find_min(int *num, int start, int end);

int ps_init(t_ps *ps, char** argv);
void sort_two_a(t_ps *ps);
void sort_two_b(t_ps *ps);
void sort_three_a(t_ps *ps);
void sort_four_a(t_ps *ps);
void sort_five_a(t_ps *ps);
void sort_three_b(t_ps *ps);
int sort_algo(t_ps *ps);
void sort_small_a(t_ps *ps);
void sort_small_b(t_ps *ps);
int add_back(t_ps *ps);

void optimizer(t_ps *ps);
int* divide_a_to_b(t_ps *ps, int start, int end);
int divide_b_to_a(t_ps *ps, int start, int end);

void push_less_than_five_b_to_a(t_ps *ps, int range);

void push_two_b_to_a(t_ps *ps);
void push_three_b_to_a(t_ps *ps);
void push_four_b_to_a(t_ps *ps);
void push_five_b_to_a(t_ps *ps);
void level(t_ps *ps);

void sort_top_three_a(t_ps *ps);
void throw_and_catch(t_ps *ps, int start, int end);


void optimizer_b(t_ps *ps);

int *sub_level_b(t_ps *ps);

#endif
