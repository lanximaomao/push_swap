/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:07:23 by lsun              #+#    #+#             */
/*   Updated: 2023/02/24 11:07:35 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


