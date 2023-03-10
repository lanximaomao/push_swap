/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:16:51 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 22:18:30 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

void	free_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	optimizer(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ps->len_a / 2)
	{
		if (ps->a[ps->len_a - i] == find_min(ps->a, j, ps->len_a - 1))
		{
			rra(ps);
			j++;
		}
		i++;
	}
	if (is_sorted(ps->a, ps->len) == 1)
		exit(0);
}
