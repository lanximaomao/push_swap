# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:23:01 by lsun              #+#    #+#              #
#    Updated: 2023/03/10 13:45:03 by lsun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = is_valid.c push_swap_utils.c push_swap_utils_2.c\
find_median.c bubble_sort.c sort_small_a.c\
main.c int_array_op.c sort_algo.c\
sort_top.c actions_push.c actions_swap.c actions_rotate.c\
actions_reverse_rotate.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJS)
	make -C libft all
	make -C libft bonus
	cc $(FLAGS) $(SRCS) -o $(NAME) libft/libft.a

$(OBJS):$(SRCS)
	cc -c $(FLAGS) $(SRCS)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re


