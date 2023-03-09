# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:23:01 by lsun              #+#    #+#              #
#    Updated: 2023/03/09 15:22:53 by lsun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = is_valid.c push_swap_utils.c find_median.c bubble_sort.c actions.c sort_small_a.c sort_small_b.c main.c int_array_op.c

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


