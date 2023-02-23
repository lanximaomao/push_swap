/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:31 by lsun              #+#    #+#             */
/*   Updated: 2023/02/23 23:17:52 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** quick sort
** radix sort
** heap sort
** insertion sort
** merge sort
*/

#include "push_swap.h"

int parition (int *num, int start, int end)
{
	int i;
	int pivot;
	int pivot_index;

	i = start;
	pivot = num[end];
	ft_printf("my pivot is %d\n", pivot);
	while (i < end)
	{
		if (num[i] > pivot)
		{
			ft_swap(num[i], pivot);
			pivot_index = i;
		}
		i++;
	}
	return(pivot_index);
}

void quick_sort(int *num, int start, int end)
{
	int pivot_index;

	pivot_index = end;
	if (start >= end)
		return;
	pivot_index = parition(num, start, pivot_index);

	quick_sort(num, start, pivot_index-1);
	quick_sort(num, pivot_index+1, end);
}

//int create_stack_a(char c)
//{
//	ft_lstnew(&c);

//}

