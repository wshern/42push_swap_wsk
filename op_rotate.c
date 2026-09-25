/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 03:21:09 by werlim            #+#    #+#             */
/*   Updated: 2026/09/26 03:32:03 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_node **node)
{
	t_node	*temp;
	t_node	*last;

	if (!node || !*node || !(*node)->next)
		return ;
	temp = (*node)->next;
	last = ftps_ndlast(*node);
	last->next = *node;
	(*node)->next = NULL;
	*node = temp;
}

void	op_ra(t_ps *ps)
{
	op_rotate(&ps->a);
	ps->counter[OP_RA]++;
	ft_printf("ra\n");
}

void	op_rb(t_ps *ps)
{
	op_rotate(&ps->b);
	ps->counter[OP_RB]++;
	ft_printf("rb\n");
}

void	op_rr(t_ps *ps)
{
	op_rotate(&ps->a);
	op_rotate(&ps->b);
	ps->counter[OP_RR]++;
	ft_printf("rr\n");
}