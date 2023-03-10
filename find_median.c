/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:53:58 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 13:47:47 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(int *num, int range)
{
	int	*num_dup;
	int	median;

	num_dup = bubble_sort(num, 0, range - 1);
	if (range % 2 == 0)
		median = num_dup[range / 2 - 1];
	else
		median = num_dup[range / 2];
	free(num_dup);
	return (median);
}

int	*bubble_sort(int *num, int start, int end)
{
	int	i;
	int	j;
	int	temp;
	int	*num_dup;

	i = start;
	num_dup = int_arr_dup(num, end - start + 1);
	while (i < end)
	{
		j = i + 1;
		while (j <= end)
		{
			if (num_dup[i] > num_dup[j])
			{
				temp = num_dup[i];
				num_dup[i] = num_dup[j];
				num_dup[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (num_dup);
}

int	*int_arr_dup(int *num, int len)
{
	int	i;
	int	*int_dup;

	i = 0;
	int_dup = malloc(sizeof(int) * len);
	if (!int_dup)
		error("malloc fail", 1);
	while (i < len)
	{
		int_dup[i] = num[i];
		i++;
	}
	return (int_dup);
}
