# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 15:22:13 by moulmado          #+#    #+#              #
#    Updated: 2022/03/10 08:25:39 by moulmado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker

INC = push_swap.h

SRCM = push_swap.c check_args.c do_best_move.c ft_atol.c ft_split.c ft_strjoin_nd_others.c get_lis.c instructions_1.c instructions_2.c instructions_3.c\
		largest_increasing_subsequence.c nb_position.c push_a.c push_to_b.c rotate_to_finish.c sort_three.c

SRCB = checker.c checker_util.c ft_atol.c ft_split.c ft_strjoin_nd_others.c get_next_line.c get_next_line_utils.c instructions_1.c instructions_2.c instructions_3.c\
		check_args.c

OBJM =$(SRCM:.c=.o)
OBJB =$(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJM) $(INC)
	@$(CC) $(CFLAGS) $(OBJM) -o $(NAME)

clean :
	@rm -rf $(OBJM) $(OBJB)

fclean : clean
	@rm -rf $(NAME) $(BNAME)

re : fclean all

bonus : $(OBJB) $(INC)
	@$(CC) $(CFLAGS) $(OBJB) -o $(BNAME)