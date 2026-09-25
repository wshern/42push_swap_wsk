/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftps_node_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:11:50 by werlim            #+#    #+#             */
/*   Updated: 2026/09/25 14:41:54 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ftps_ndnew(int data, int rank)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->rank = rank;
	node->next = NULL;
	return (node);
}

t_node *ftps_ndlast(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ftps_ndaddlast(t_node **node, t_node *new)
{
	t_node	*temp;

	if (!node || !new)
		return ;
	if (!*node)
	{
		*node = new;
		return ;
	}
	temp = ftps_ndlast(*node);
	temp->next = new;
}

void	ftps_ndclear(t_node **node)
{
	t_node	*temp;

	while (*node != NULL)
	{
		temp = (*node)->next;
		free(*node);
		*node = temp;
	}
}

