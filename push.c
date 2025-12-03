/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:26 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 22:12:17 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*node_to_push;
	t_node	*src_first;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	src_first = node_to_push->next;
	*src = src_first;
	if (src_first)
		src_first->prev = NULL;
	node_to_push->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_push;
	node_to_push->prev = NULL;
	*dest = node_to_push;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
