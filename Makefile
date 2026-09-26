# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/27 00:41:53 by werlim            #+#    #+#              #
#    Updated: 2026/09/27 01:39:00 by werlim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
PRINTF_DIR	=	ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

INCLUDES	=	-I. -I$(LIBFT_DIR) -I$(PRINTF_DIR)

SRCS	=	push_swap.c op_swap.c op_push.c op_rotate.c op_rev_rotate.c\
			ftps_node_helper.c

OBJS	=	$(SRCS:.c=.o)

all: libs $(NAME)

libs:
	$(MAKE) -C $(LIBFT_DIR)
	&(MAKE) -C $(PRINTF_DIR)
	
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all libs clean fclean re