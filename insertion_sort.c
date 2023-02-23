/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:53:58 by lsun              #+#    #+#             */
/*   Updated: 2023/02/23 23:21:07 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(int *num, int count)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 1;

	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_print_int_array(num, count);
}

int find_max(int *num, int count)
{
	int i;
	int max;

	i = 0;
	max = num[i];
	while (i < count)
	{
		if (num[i] > max)
			max = num[i];
		i++;
	}
	ft_printf("my max is %d: \n", max);
	return(max);
}

//int find_binary_digits(int num)
//{
//	while (num > 1)
//	{
//		ft_printf("%d\n", num % 2);
//		num = num / 2;
//	}
//	if (num == 1)
//	{
//		ft_printf("%d\n", num % 2);
//		return (1);
//	}
//}

void radix_sort(int *stack_a, int count)
{
	//int i;
	int* stack_b;
	int digit_num;

	stack_b = malloc(sizeof(int) * count);
	if (!stack_b)
		return;
	digit_num = ft_digit_num(find_max(stack_a, count));
	ft_printf("my digit num is %d\n", digit_num);
	//find_binary_digits(4);
}


