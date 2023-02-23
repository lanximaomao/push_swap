# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:20:32 by lsun              #+#    #+#              #
#    Updated: 2023/02/23 23:20:24 by linlinsun        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = is_valid.c push_swap_utils.c insertion_sort.c main.c

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


