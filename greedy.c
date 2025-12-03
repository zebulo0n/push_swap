/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:36 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 16:29:49 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*calculate_cheapest(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*cheapest;

	set_current(a, b);
	tmp = *b;
	cheapest = tmp;
	while (tmp)
	{
		reset_cost(tmp);
		calculate_cost(tmp, a, b);
		optimize_cost(tmp);
		calculate_total(tmp);
		if (tmp->cost.total <= cheapest->cost.total)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	calculate_cost(t_node *base, t_node **a, t_node **b)
{
	t_node	*target;

	reset_cost(base);
	target = find_target(base, a);
	base_on_top(base, b);
	target_on_top(base, target, a);
}

t_node	*find_target(t_node *base, t_node **a)
{
	t_node	*tmp;
	t_node	*best;
	int		min_diff;
	int		diff;

	tmp = *a;
	best = NULL;
	min_diff = 2147483647;
	while (tmp)
	{
		diff = tmp->index - base->index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			best = tmp;
		}
		tmp = tmp->next;
	}
	if (!best)
		best = find_min_index(a);
	return (best);
}

void	base_on_top(t_node *base, t_node **b)
{
	int	i;
	int	len;

	len = stack_len(*b);
	if (base->current == 0)
		return ;
	else if (base->current <= (len / 2))
	{
		i = base->current;
		while (i > 0)
		{
			base->cost.rb++;
			i--;
		}
	}
	else
	{
		i = base->current;
		while (i < len)
		{
			base->cost.rrb++;
			i++;
		}
	}
}

void	target_on_top(t_node *base, t_node *target, t_node **a)
{
	int	i;
	int	len;

	len = stack_len(*a);
	if (target->current == 0)
		return ;
	else if (target->current <= (len / 2))
	{
		i = target->current;
		while (i > 0)
		{
			base->cost.ra++;
			i--;
		}
	}
	else
	{
		i = target->current;
		while (i < len)
		{
			base->cost.rra++;
			i++;
		}
	}
}
