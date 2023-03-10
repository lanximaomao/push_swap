/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:53:58 by lsun              #+#    #+#             */
/*   Updated: 2023/03/10 23:09:33 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(int *num, int range)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < range)
	{
		j = 0;
		count = 0;
		while (j < range)
		{
			if (i != j && num[i] < num[j])
				count++;
			j++;
		}
		if (count == range / 2)
		{
			return (num[i]);
		}
		i++;
	}
	ft_printf("median not found!\n");
	return (0);
}
