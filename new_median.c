/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:53:58 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 19:39:53 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_median(int *num, int range)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < range - 1)
	{
		j = 0;
		count = 0;
		while(j <= range - 1)
		{
			printf("i = %d && j = %d\n", i, j);
			if (num[i] > num[j])
				count++;
			j++;
		}
		printf("count = %d\n", count);
		if (count == range / 2 && range % 2 == 1)
		{
			printf("median1 = %d \n", num[i]);
			return(num[i]);
		}
		if (count == (range / 2 - 1 ) && range % 2 == 0)
		{
			printf("median2 = %d \n", num[i]);
			return(num[i]);
		}
		i++;
	}
	printf("median not found!\n");
	return(0);
}

//int main()
//{
//	int num[] = {1969784712, 692506731, -170058725, 341534341, 504767186};
//	printf("my new median is %d\n", find_median(num, 10));
//	return (0);
//}
