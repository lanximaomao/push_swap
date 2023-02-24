/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:53:58 by lsun              #+#    #+#             */
/*   Updated: 2023/02/24 18:54:48 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//first duplicate the int array and then sort in place

int* bubble_sort(int *num, int start, int end)
{
	int i;
	int j;
	int temp;
	int *num_dup;

	i = start;
	num_dup = int_arr_dup(num, end - start + 1);//free
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
	return(num_dup);
}

//int bubble_sort(int *num, int start, int end)
//{
//	int i;
//	int j;
//	int temp;
//	int median;

//	i = start;
//	while (i < end)
//	{
//		j = i + 1;
//		while (j <= end)
//		{
//			if (num[i] > num[j])
//			{
//				temp = num[i];
//				num[i] = num[j];
//				num[j] = temp;
//			}
//			j++;
//		}
//		i++;
//	}
//	median = find_median(num, end - start + 1);
//	ft_printf("after sorting: ");
//	ft_print_int_array(num, end - start + 1);
//	ft_printf("my median value is %d\n", median);
//	return(median);
//}

//int main(void)
//{
//	int arr[] = {5, 2, 9, 3, 7, 4, 8, 6};
//	bubble_sort(arr, 8);
//	return(0);
//}

int	find_median(int *num, int start, int end)
{
	int *num_dup;
	int len;
	int median;

	len = end - start + 1;
	num_dup = bubble_sort(num, start, end);
	ft_printf("if sorted: ");
	ft_print_int_array(num_dup, end - start + 1);
	median = num_dup[len/2 ];
	free(num_dup);
	return(median);
	//if (len < 3)
	//{
	//	free(num_dup);
	//	return(num_dup[len - 1]);
	//}
	//if (len % 2 == 1)
	//{
	//	free(num_dup);
	//	return(num_dup[len/2]);
	//}
	//else
	//{
	//	free(num_dup);
	//	return(num_dup[len/2 - 1]);
	//}
}

//int main()
//{
//	int ret;

//	int num[] = {3, 1,2 };
//	ret = find_median(num, 0, 2);
//	ft_printf("ret is %d\n", ret);
//	return(0);
//}
