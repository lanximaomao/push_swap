/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:55:37 by lsun              #+#    #+#             */
/*   Updated: 2023/03/12 23:05:55 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
	int		*lvl_b;
	int		action_count;
}			t_ps;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* main*/
int			main(int argc, char **argv);
void		checker(t_ps *ps);
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

/* is_valid */
t_ps		*is_uniq(t_ps *ps);
void		is_numeric(char **str, int i, int j);
t_ps		*check_for_length(t_ps *ps);
t_ps		*parsing(t_ps *ps);

/* push_swap_utils*/
void		write_and_exit(void);
void		error(char *msg, int error_code);
void		free_char(char **str);

/* push_swap_utils part2 */
int			is_sorted(int *num, int len);
void		ft_print_int_array(int *int_arr, int len);

#endif
