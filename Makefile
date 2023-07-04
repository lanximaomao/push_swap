# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 17:23:01 by lsun              #+#    #+#              #
#    Updated: 2023/07/04 19:32:59 by lsun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
SRCS = 	is_valid.c push_swap_utils.c push_swap_utils_2.c find_median.c\
		sort_small_a.c int_array_op.c sort_algo.c sort_top.c actions_push.c\
		actions_swap.c actions_rotate.c actions_reverse_rotate.c

SRCS_BONUS =is_valid.c push_swap_utils.c push_swap_utils_2.c\
			actions_push_bonus.c actions_swap_bonus.c actions_rotate_bonus.c\
			actions_reverse_rotate_bonus.c

SRCS_DEST = $(addprefix ./SRCS/, $(SRCS))
SRCS_BONUS_DEST = $(addprefix ./SRCS_BONUS/, $(SRCS))
HEADER = includes/push_swap.h
HEADER_BONUS = includes/push_swap_bonus.h
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a

all: $(NAME)

$(NAME):$(SRCS_DEST)
	make -C libft all
	make -C libft bonus
	cc $(FLAGS) $(SRCS_DEST) -o $(NAME) $(LIB) main.c

bonus: $(NAME) $(NAME_BONUS)

$(NAME_BONUS):$(SRCS_BONUS_DEST)
	cc $(FLAGS) $(SRCS_BONUS_DEST) -o $(NAME_BONUS) $(LIB) checker.c

clean:
	make -C libft clean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean:clean
	rm -f libft/libft.a
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
