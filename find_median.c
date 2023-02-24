/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:11:28 by lsun              #+#    #+#             */
/*   Updated: 2023/02/24 14:19:59 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



//int	main(void)
//{
//	int	median;

//	int arr[] = {5, 2, 9, 3, 7, 4, 8, 1, 6}; // example integer array
//	int n = sizeof(arr) / sizeof(arr[0]);    // number of elements in array
//	// find the median value using quickselect algorithm
//	if (n % 2 == 0)
//	{
//		median = (quickselect(arr, 0, n - 1, n / 2 - 1) + quickselect(arr, 0, n
//					- 1, n / 2)) / 2;
//	}
//	else
//	{
//		median = quickselect(arr, 0, n - 1, n / 2);
//	}
//	printf("Median value: %d\n", median);
//	return (0);
//}

//int	quickselect(int arr[], int left, int right, int k)
//{
//	int	pivot;
//	int	i;
//	int	j;
//	int	temp;

//	if (left == right)
//	{
//		return (arr[left]);
//	}
//	pivot = arr[(left + right) / 2];
//	i = left;
//	j = right;
//	while (i <= j)
//	{
//		while (arr[i] < pivot)
//		{
//			i++;
//		}
//		while (arr[j] > pivot)
//		{
//			j--;
//		}
//		if (i <= j)
//		{
//			temp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = temp;
//			i++;
//			j--;
//		}
//	}
//	if (k <= j)
//	{
//		return (quickselect(arr, left, j, k));
//	}
//	else if (k >= i)
//	{
//		return (quickselect(arr, i, right, k));
//	}
//	else
//	{
//		return (arr[k]);
//	}
//}
