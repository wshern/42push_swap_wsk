/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 04:01:47 by werlim            #+#    #+#             */
/*   Updated: 2026/09/26 04:22:41 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrotate(t_node **node)
{
	t_node	*last;
	t_node	*prev;

	if (!node || !*node || !(*node)->next)
		return ;
	prev = *node;
	last = ftps_ndlast(*node);
	while (prev->next != last)
		prev = prev->next;
	last->next = *node;
	prev->next = NULL;
	*node = last;
}

void	op_rra(t_ps *ps)
{
	op_rrotate(&ps->a);
	ps->counter[OP_RRA]++;
	ft_printf("rra\n");
}

void	op_rrb(t_ps *ps)
{
	op_rrotate(&ps->b);
	ps->counter[OP_RRB]++;
	ft_printf("rrb\n");
}

void	op_rrr(t_ps *ps)
{
	op_rrotate(&ps->a);
	op_rrotate(&ps->b);
	ps->counter[OP_RRR]++;
	ft_printf("rrr\n");
}