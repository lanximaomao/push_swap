/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:53:58 by lsun              #+#    #+#             */
/*   Updated: 2023/02/24 13:10:25 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort in place
int bubble_sort(int *num, int count)
{
	int i;
	int j;
	int temp;
	int median;

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
	median = find_median(num, count);
	ft_printf("after sorting: ");
	ft_print_int_array(num, count);
	ft_printf("my median value is %d\n", median);
	return(median);
}

//int main(void)
//{
//	int arr[] = {5, 2, 9, 3, 7, 4, 8, 6};
//	bubble_sort(arr, 8);
//	return(0);
//}
