/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:36:11 by linlinsun         #+#    #+#             */
/*   Updated: 2023/03/11 08:52:34 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap_bonus.h"
# include "libft/get_next_line.h"

/*
** ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
*/

void read_stdout()
{
	char *buf;
	int read_num;

	buf = malloc(sizeof(char)* BUFFER_SIZE);
	if (!buf)
		error("malloc fail", 1);
	read_num = BUFFER_SIZE;
	while (read_num != 0)
	{
		read_num = read(1, buf, BUFFER_SIZE);
		ft_printf("I read %d chars.\n", read_num);
	}
}

void apply_actions()
{
	return;
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

	ft_printf("argv[0] = %s\n, argv[1] = %s\n, argv[2] = %s\n", argv[0], argv[1], argv[2]);
	// read stdout
	read_stdout();

	//compare the strings
	apply_actions();

	//check if sorted or not
	if (is_sorted(ps->a, ps->len_a) == 1 && ps->len_b == 0)
	{
		write(1, "OK\n", 3);
		ft_printf("sorting %d numbers takes %d actions.\n", ps->len_a, ps->action_count);
		ft_printf("\na: ");
		ft_print_int_array(ps->a, ps->len_a);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "KO\n", 3);
		ft_printf("\na: ");
		ft_print_int_array(ps->a, ps->len_a);
		write(1, "\n", 1);
	}
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
