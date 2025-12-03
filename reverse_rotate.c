/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:31 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/03 15:44:42 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*to_rrotate;
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	to_rrotate = get_last(*stack);
	first = *stack;
	last = to_rrotate->prev;
	to_rrotate->next = first;
	last->next = NULL;
	to_rrotate->prev = NULL;
	first->prev = to_rrotate;
	*stack = to_rrotate;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_a_b(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
