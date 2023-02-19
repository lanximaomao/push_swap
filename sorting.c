/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:31 by lsun              #+#    #+#             */
/*   Updated: 2023/02/19 23:26:48 by linlinsun        ###   ########.fr       */
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

void ft_swap (int i, int j)
{
	int temp;

	temp = i;
	i = j;
	j = temp;
}

int parition (int *num, int start, int end)
{
	int i;
	int ret;
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

	if (start >= end)
		return;
	pivot_index = parition(num, start, pivot_index);

	quick_sort(num, start, pivot_index);
	quick_sort(num, pivot_index+1, end);
}

//int create_stack_a(char c)
//{
//	ft_lstnew(&c);

//}

int main(int argc, char** argv)
{
	t_ps *ps;

	if (argc == 1)
		return(0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps->input = argv + 1;
	check_for_length(argc, ps);
	//ft_printf("len is %d\n", ps->len);
	ps->int_array = malloc(sizeof(int)*ps->len);
	if (!ps->int_array)
		error("malloc fail", 1);
	//
	is_uniq(parsing(argc, ps));
	//ft_print_int_array(ps->int_array, ps->len);
	// sorting
	//quick_sort(ps->int_array, 0, ps->len);
	ft_print_int_array(ps->int_array, ps->len);
	//create stack
	create_stack(ps);

	//free
	free(ps->int_array);
	free(ps);
	return(0);
}
