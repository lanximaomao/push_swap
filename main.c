/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:52:57 by lsun              #+#    #+#             */
/*   Updated: 2023/03/12 23:07:03 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps_init(ps, argv);
	sort_algo(ps);
	free(ps->a);
	free(ps->b);
	free(ps->lvl_b);
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
	if (ps->len_a <= 3)
	{
		sort_small_a(ps);
		exit(0);
	}
	ps->len = ps->len_a;
	ps->lvl = 1;
	ps->lvl_b = malloc(sizeof(int) * 1);
	if (!ps->lvl_b)
		error("malloc failure", 1);
	ps->lvl_b[0] = 0;
	return (0);
}
