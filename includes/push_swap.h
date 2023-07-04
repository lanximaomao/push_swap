/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:55:37 by lsun              #+#    #+#             */
/*   Updated: 2023/07/04 18:57:28 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
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
	int		*lvl_b;
	int		action_count;
}			t_ps;

/* main*/
int			main(int argc, char **argv);
int			ps_init(t_ps *ps, char **argv);

/* actions */
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

/* find_median */
int			find_median(int *num, int range);

/* int_array_op */
void		add_one_num_front(t_ps *ps, int data);
void		remove_one_num_front(t_ps *ps);

/* is_valid */
t_ps		*is_uniq(t_ps *ps);
void		is_numeric(char **str, int j);
t_ps		*check_for_length(t_ps *ps);
t_ps		*parsing(t_ps *ps);

/* push_swap_utils*/
void		write_and_exit(void);
void		error(char *msg, int error_code);
void		free_char(char **str);
void		optimizer(t_ps *ps);

/* push_swap_utils part2 */
int			find_max(int *num, int start, int end);
int			find_min(int *num, int start, int end);
void		ft_print_int_array(int *int_arr, int len);
int			is_sorted(int *num, int len);
int			is_sorted_reverse(int *num, int len);

/* sort_algo */
int			sort_algo(t_ps *ps);
void		op(t_ps *ps, int range);
void		first_divide_a_to_b(t_ps *ps, int range);
void		divide_a_to_b(t_ps *ps, int range);
void		divide_b_to_a(t_ps *ps, int range);

/* sort_small_a */
void		sort_small_a(t_ps *ps);
void		sort_two_a(t_ps *ps);
void		sort_three_a(t_ps *ps);

/* sort_top*/
void		sort_top_a(t_ps *ps, int range);
void		sort_top_b(t_ps *ps, int range);
void		push_b2a(t_ps *ps, int range);

#endif
