/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:28:10 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 14:07:13 by lsun             ###   ########.fr       */
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

int	is_sorted(int *num, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (num[i] > num[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_reverse(int *num, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (num[i] < num[i + 1])
			return (0);
		i++;
	}
	return (1);
}
