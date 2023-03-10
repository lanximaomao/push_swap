/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:28:10 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 13:28:38 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *num, int start, int end)
{
	int	max;

	max = num[start];
	while (start <= end)
	{
		if (num[start] > max)
			max = num[start];
		start++;
	}
	return (max);
}

int	find_min(int *num, int start, int end)
{
	int	min;

	min = num[start];
	while (start <= end)
	{
		if (num[start] < min)
			min = num[start];
		start++;
	}
	return (min);
}

void	push_b2a(t_ps *ps, int range)
{
	while (range > 0)
	{
		pa(ps);
		range--;
	}
}
