/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:34 by lsun              #+#    #+#             */
/*   Updated: 2023/02/20 16:59:02 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gcc is_valid.c push_swap_utils.c libft/libft.a
// ./push_swap "+1 -2 3 5abc" -3 34 "125"
// ./push_swap "+"
// should I save the parsing result linked before or after the validity check for all the input num?

t_ps* is_uniq(t_ps *ps)
{
	int i;
	int j;

	if (ps->len == 1)
		return(0);
	i = 0;
	j = 1;
	while (i < ps->len)
	{
		j = i + 1;
		while (j < ps->len)
		{
			if (ps->int_array[i] == ps->int_array[j])
				write_and_exit();
			j++;
		}
		i++;
	}
	return(ps);
}

void is_numeric(char **str, int i, int j)
{
	int num;
	char *res_itoa;
	char *res_strjoin;

	num = ft_atoi(str[j]);
	res_itoa = ft_itoa(num);
	res_strjoin = ft_strjoin("+", res_itoa);
	if (str[j][0] == '+' && ft_strncmp(res_strjoin, str[i], ft_strlen(str[j])+1)!= 0)
		write_and_exit();
	else if (str[j][0] != '+' && ft_strncmp(res_itoa, str[j], ft_strlen(str[j])) != 0)
		write_and_exit();
	free(res_itoa);
	free(res_strjoin);
}

t_ps* check_for_length(t_ps *ps)
{
	int i;
	int j;
	int num;
	char **split_input;

	i = 0;
	j = 0;
	ps->len = 0;

	while (ps->input[i])
	{
		split_input = ft_split(ps->input[i], ' ');
		if (!split_input)
			error("split function fail", 1);
		j = 0;
		while (split_input[j])
		{
			num = ft_atoi(split_input[j]);
			is_numeric(split_input, i, j);
			ps->len++;
			j++;
		}
		free_char(split_input);
		i++;
	}
	return(ps);
}

t_ps* parsing(t_ps *ps)
{
	int i;
	int j;
	int k;
	char **split_input;

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
			ps->int_array[k] = ft_atoi(split_input[j]);
			j++;
			k++;
		}
		free_char(split_input);
		i++;
	}
	return(ps);
}

int main(int argc, char** argv)
{
	t_ps *ps;

	if (argc == 1)
		return(0);
	ps = malloc(sizeof(t_ps));
	if (!ps)
		error("malloc fail", 1);
	ps->input = argv + 1;
	check_for_length(ps);
	//ft_printf("len is %d\n", ps->len);
	ps->int_array = malloc(sizeof(int)*ps->len);
	if (!ps->int_array)
		error("malloc fail", 1);
	//
	is_uniq(parsing(ps));
	//ft_print_int_array(ps->int_array, ps->len);
	// sorting
	//quick_sort(ps->int_array, 0, ps->len);
	ft_print_int_array(ps->int_array, ps->len);
	//create stack
	//create_stack(ps);

	//free
	free(ps->int_array);
	free(ps);
	return(0);
}



