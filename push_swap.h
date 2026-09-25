/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:37:21 by werlim            #+#    #+#             */
/*   Updated: 2026/09/25 20:53:06 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

/* Operations - Swap */
void	op_swap(t_node **node);
void	op_sa(t_ps *ps);
void	op_sb(t_ps *ps);
void	op_ss(t_ps *ps);

/* Linked List Helper Functions */
t_node	*ftps_ndnew(int data, int rank);
t_node	*ftps_ndlast(t_node *node);
void	ftps_ndaddlast(t_node **node, t_node *new);
void	ftps_ndclear(t_node **node);

typedef struct s_node
{
	int				data;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_NUM
}	t_op;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	int		counter[OP_NUM];
}	t_ps;

#endif