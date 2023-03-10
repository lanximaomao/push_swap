/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:03:59 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 10:59:18 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void remove_one_num_front(t_ps *ps)
{
	int i;
	int *num_minus;

	i = 0;
	num_minus = malloc(sizeof(int) * (ps->lvl - 1)); // remember to free
	if (!num_minus)
		error("malloc failure", 1);
	while (i + 1 < ps->lvl)
	{
		num_minus[i] =  ps->lvl_b [i + 1];
		i++;
	}
	free(ps->lvl_b);
	ps->lvl_b = num_minus;
}

void	ft_print_int_array(int *int_arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d  ", int_arr[i]);
		i++;
	}
	ft_printf("\n");
}



void level_b_init(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->lvl + 1)
	{
		ps->lvl_b[i] = 0;
		i++;
	}
}

//void level(t_ps *ps)
//{
//	int	i;
//	int tmp;

//	i = 0;
//	ps->lvl = 0;
//	tmp = ps->len;;
//	while (tmp > 3)
//	{
//		tmp = tmp / 2 + tmp % 2;
//		ps->lvl++;
//	}
//	ft_printf("\n\n---------------------------------");
//	ft_printf("\nlvl in b is %d\n", ps->lvl);
//	ps->lvl_b = malloc(sizeof(int) * ps->lvl + 1);
//	if (!ps->lvl_b)
//		error("malloc fail", 1);
//	level_b_init(ps);
//	tmp = ps->len;
//	while (tmp > 3)
//	{
//		ps->lvl_b[i] = tmp/2;
//		ft_printf("level %d is has %d numbers\n", i, ps->lvl_b[i]);
//		tmp = tmp / 2 + tmp % 2;
//		i++;
//	}
//	ft_printf("---------------------------------\n\n");
//}

int is_sorted(int *num, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (num[i] > num[i + 1])
			return(0);
		i++;
	}
	return(1);
}

int is_sorted_reverse(int *num, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (num[i] < num[i + 1])
			return(0);
		i++;
	}
	return(1);
}

void push_b2a(t_ps *ps, int range)
{
	while (range > 0)
	{
		pa(ps);
		range--;
	}
}
