/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:30 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 16:37:23 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current(t_node **a, t_node **b)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->current = i;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = *b;
	while (tmp)
	{
		tmp->current = i;
		tmp = tmp->next;
		i++;
	}
}

void	optimize_cost(t_node *base)
{
	while (base->cost.ra > 0 && base->cost.rb > 0)
	{
		base->cost.rr++;
		base->cost.ra--;
		base->cost.rb--;
	}
	while (base->cost.rra > 0 && base->cost.rrb > 0)
	{
		base->cost.rrr++;
		base->cost.rra--;
		base->cost.rrb--;
	}
}

void	calculate_total(t_node *base)
{
	base->cost.total = base->cost.ra + base->cost.rb + base->cost.rra
		+ base->cost.rrb + base->cost.rr + base->cost.rrr + 1;
}

void	reset_cost(t_node *node)
{
	node->cost.ra = 0;
	node->cost.rb = 0;
	node->cost.rra = 0;
	node->cost.rrb = 0;
	node->cost.rr = 0;
	node->cost.rrr = 0;
	node->cost.total = 0;
}

t_node	*find_min_index(t_node **a)
{
	t_node	*tmp;
	t_node	*best;

	tmp = *a;
	best = tmp;
	while (tmp)
	{
		if (tmp->index < best->index)
			best = tmp;
		tmp = tmp->next;
	}
	return (best);
}
