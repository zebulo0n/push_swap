/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:34 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/03 15:44:24 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*to_rotate;
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	to_rotate = *stack;
	last = get_last(*stack);
	first = to_rotate->next;
	last->next = to_rotate;
	to_rotate->next = NULL;
	first->prev = NULL;
	to_rotate->prev = last;
	*stack = first;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rotate_a_b(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}
