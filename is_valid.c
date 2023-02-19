/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:34 by lsun              #+#    #+#             */
/*   Updated: 2023/02/19 19:26:20 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ./push_swap "+1 -2 3 5abc" -3 34 "125"
// should I save the parsing result linked before or after the validity check for all the input num?

//int is_uniq(int num)
//{
//	//check for any duplicates
//}


int parsing(int argc, char**argv)
{
	int i;
	int j;
	int num;
	int len;
	char **input;
	char **split_input;

	i = 0;
	j = 0;
	len = 0;
	input = argv + 1;

	while (input[i])
	{
		split_input = ft_split(input[i], ' ');//free in a loop
		if (!split_input)
			error("split function fail", 1); // what if the input argument is ""
		j = 0;
		while (split_input[j])
		{
			num = ft_atoi(split_input[j]);
			if (ft_strncmp(ft_itoa(num), split_input[j], ft_strlen(split_input[j])) != 0)
			{
				write(1, "error\n", 6);
				exit(1);
			}
			len++;
			j++;
		}
		i++;
	}
	return(len);
}


void error(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

int main(int argc, char** argv)
{
	if (argc == 1)
		return(0);
	ft_printf("len is %d\n", parsing(argc, argv));
	//ft_printf("%s\n", ft_itoa(ft_atoi("a")));
	return(0);
}
