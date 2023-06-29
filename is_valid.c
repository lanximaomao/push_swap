/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:34 by lsun              #+#    #+#             */
/*   Updated: 2023/03/13 11:15:18 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*check_for_length(t_ps *ps)
{
	int		i;
	int		j;
	int		num;
	char	**split_input;

	i = 0;
	j = 0;
	ps->len_a = 0;
	while (ps->input[i])
	{
		split_input = ft_split(ps->input[i], ' ');
		if (!split_input)
			error("split function fail", 1);
		j = 0;
		while (split_input[j])
		{
			num = ft_atoi(split_input[j]);
			is_numeric(split_input, j);
			ps->len_a++;
			j++;
		}
		free_char(split_input);
		i++;
	}
	return (ps);
}

void	is_numeric(char **str, int j)
{
	int		num;
	char	*res_itoa;
	char	*res_strjoin;

	num = ft_atoi(str[j]);
	res_itoa = ft_itoa(num);
	res_strjoin = ft_strjoin("+", res_itoa);
	if (!res_itoa || !res_strjoin)
		error("malloc failure", 1);
	if (ft_strlen(str[j]) == 2 && str[j][0] == '-' && str[j][1] == '0')
	{
		free(res_itoa);
		free(res_strjoin);
		return ;
	}
	else if (str[j][0] == '+' && ft_strncmp(res_strjoin, str[j],
				ft_strlen(str[j]) + 1) != 0)
		write_and_exit();
	else if (str[j][0] != '+' && ft_strncmp(res_itoa, str[j],
				ft_strlen(str[j])) != 0)
		write_and_exit();
	free(res_itoa);
	free(res_strjoin);
}

t_ps	*parsing(t_ps *ps)
{
	int		i;
	int		j;
	int		k;
	char	**split_input;

	i = 0;
	j = 0;
	k = 0;
	while (ps->input[i])
	{
		split_input = ft_split(ps->input[i], ' ');
		if (!split_input)
			error("split function fail", 1);
		j = 0;
		while (split_input[j])
		{
			ps->a[k] = ft_atoi(split_input[j]);
			j++;
			k++;
		}
		free_char(split_input);
		i++;
	}
	return (ps);
}

t_ps	*is_uniq(t_ps *ps)
{
	int	i;
	int	j;

	if (ps->len_a == 1)
		return (0);
	i = 0;
	j = 1;
	while (i < ps->len_a)
	{
		j = i + 1;
		while (j < ps->len_a)
		{
			if (ps->a[i] == ps->a[j])
				write_and_exit();
			j++;
		}
		i++;
	}
	return (ps);
}
