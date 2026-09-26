# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/27 00:41:53 by werlim            #+#    #+#              #
#    Updated: 2026/09/27 00:46:50 by werlim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	push_swap.c op_swap.c op_push.c op_rotate.c op_rev_rotate.c\
			ftps_node_helper.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re