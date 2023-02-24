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
	int		len_a;
	int		len_b;
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
//quick sort
int bubble_sort(int *num, int count);
void		quick_sort(int *num, int start, int end);
int			parition(int *num, int start, int end);
void		ft_swap(int i, int j);
int	find_median(int *num, int len);

//utils
int* int_arr_dup(int *num, int len);

#endif
