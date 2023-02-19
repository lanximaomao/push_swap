/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:34 by lsun              #+#    #+#             */
/*   Updated: 2023/02/19 20:10:33 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gcc is_valid.c push_swap_utils.c libft/libft.a
// ./push_swap "+1 -2 3 5abc" -3 34 "125"
// should I save the parsing result linked before or after the validity check for all the input num?

//int is_uniq(int num)
//{
//	//check for any duplicates
//}

void error(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

void write_and_exit()
{
	write(1, "Error\n", 6);
	exit(1);
}

t_ps* check_for_length(int argc, t_ps *ps)
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
		split_input = ft_split(ps->input[i], ' ');//free in a loop
		if (!split_input)
			error("split function fail", 1); // what if the input argument is ""
		j = 0;
		while (split_input[j])
		{
			num = ft_atoi(split_input[j]);
			if (ft_strncmp(ft_itoa(num), split_input[j], ft_strlen(split_input[j])) != 0)
				write_and_exit();
			ps->len++;
			j++;
		}
		free_char(split_input);
		i++;
	}
	return(ps);
}

t_ps* parsing(int argc, t_ps *ps)
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
		split_input = ft_split(ps->input[i], ' ');//free in a loop
		if (!split_input)
			error("split function fail", 1); // what if the input argument is ""
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
	check_for_length(argc, ps);
	ft_printf("len is %d\n", ps->len);
	ps->int_array = malloc(sizeof(int)*ps->len);
	if (!ps->int_array)
		error("malloc fail", 1);
	parsing(argc, ps);
	ft_print_int_array(ps->int_array, ps->len);

	free(ps->int_array);
	free(ps);
	return(0);
}

