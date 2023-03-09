/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:22:45 by lsun              #+#    #+#             */
/*   Updated: 2023/03/08 16:09:47 by lsun             ###   ########.fr       */
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

void ft_swap(int *a, int*b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int parition (int *num, int start, int end)
{
	int i;
	int temp;
	int pivot;
	int pivot_index;

	i = start;
	pivot = num[end];
	pivot_index = start;
	//ft_printf("\nmy pivot is %d\n", pivot);
	while (i < end)
	{
		if (num[i] < pivot)
		{
			ft_swap(&num[i], &num[pivot_index]);
			pivot_index++;
		}
		i++;
	}
	if (num[pivot_index > pivot])
		ft_swap(&num[pivot_index], &num[end]);
	return(pivot_index);
}

void quick_sort(int *num, int start, int end)
{
	int pivot_index;

	pivot_index = end;
	if (start >= end)
		return;
	ft_printf("\nmy start is %d && my end is %d && pivot %d\n", start, end, num[end]);
	pivot_index = parition(num, start, end);
	quick_sort(num, start, pivot_index-1);
	ft_putstr_fd("\nfirst quick sort\n", 2);
	quick_sort(num, pivot_index+1, end);
	ft_putstr_fd("\nsecond quick sort\n",2);
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
	//ft_printf("\n");
}

int main()
{
	int num[] = {9, 7, 2, 4, 3, 10, 5};
	quick_sort(num, 0, 6);
	ft_print_int_array(num, 7);
	return(0);
}
