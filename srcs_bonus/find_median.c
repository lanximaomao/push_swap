/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:13:50 by lsun              #+#    #+#             */
/*   Updated: 2023/07/04 19:17:57 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
