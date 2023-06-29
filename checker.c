/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:13:37 by lsun              #+#    #+#             */
/*   Updated: 2023/03/13 11:13:39 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "push_swap_bonus.h"

/*
** ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
** ARG="45a"; ./checker $ARG --> Error
** ARG="45 32"; ./push_swap $ARG | ./checker $ARG -->
*/

void	apply_actions(char *buf, t_ps *ps)
{
	if (ft_strncmp(buf, "pa\n", 3) == 0)
		pa(ps);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		pb(ps);
	else if (ft_strncmp(buf, "sa\n", 3) == 0)
		sa(ps);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		sb(ps);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
		ss(ps);
	else if (ft_strncmp(buf, "ra\n", 3) == 0)
		ra(ps);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		rb(ps);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
		rr(ps);
	else if (ft_strncmp(buf, "rra\n", 4) == 0)
		rra(ps);
	else if (ft_strncmp(buf, "rrb\n", 4) == 0)
		rrb(ps);
	else if (ft_strncmp(buf, "rrr\n", 4) == 0)
		rrr(ps);
}

void	read_and_play(t_ps *ps)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(0);
		if (buf == NULL)
			break ;
		apply_actions(buf, ps);
	}
	free(buf);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps_init(ps, argv);
	read_and_play(ps);
	if (is_sorted(ps->a, ps->len_a) == 1 && ps->len_b == 0)
	{
		write(1, "OK\n", 3);
		ft_printf("--------------------------------------------");
		ft_printf("\nAfter sorting stack a will be: ");
		ft_print_int_array(ps->a, ps->len_a);
		ft_printf("\nsorting %d numbers takes %d actions.\n", ps->len_a,
			ps->action_count);
		ft_printf("--------------------------------------------\n");
	}
	else
		write(1, "KO\n", 3);
	free(ps->a);
	free(ps->b);
	free(ps);
	return (0);
}

int	ps_init(t_ps *ps, char **argv)
{
	ps->input = argv + 1;
	check_for_length(ps);
	if (ps->len_a <= 1)
		exit(0);
	ps->a = malloc(sizeof(int) * ps->len_a);
	ps->b = malloc(sizeof(int) * ps->len_a);
	ps->len_b = 0;
	if (!ps->a || !ps->b)
		error("malloc fail", 1);
	is_uniq(parsing(ps));
	ps->action_count = 0;
	return (0);
}
