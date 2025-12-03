/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:37 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 19:27:50 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = stack_len(*a);
	if (size == 2)
	{
		sa(a);
		return ;
	}
	while (size < 6 && size > 3)
	{
		pb(a, b);
		size--;
	}
	if (size == 3)
		sort_three(a);
	if (size > 5)
		lis_sort(a, b);
	exec_sort(a, b);
}

void	sort_three(t_node **stack)
{
	int	max;

	max = find_max(*stack);
	if ((*stack)->nb == max)
		ra(stack);
	else if ((*stack)->next->nb == max)
		rra(stack);
	if (!is_sorted(*stack))
		sa(stack);
}

void	exec_sort(t_node **a, t_node **b)
{
	t_node	*cheapest;

	while (*b)
	{
		cheapest = calculate_cheapest(a, b);
		exec_rr_rrr(a, b, cheapest);
		exec_ra_rb_rra_rrb(a, b, cheapest);
		pa(a, b);
	}
	if (find_min(a) == 0)
	{
		while (!is_sorted(*a))
			ra(a);
	}
	else
	{
		while (!is_sorted(*a))
			rra(a);
	}
}

void	exec_rr_rrr(t_node **a, t_node **b, t_node *cheapest)
{
	while (cheapest->cost.rrr > 0)
	{
		rrr(a, b);
		cheapest->cost.rrr--;
	}
	while (cheapest->cost.rr > 0)
	{
		rr(a, b);
		cheapest->cost.rr--;
	}
}

void	exec_ra_rb_rra_rrb(t_node **a, t_node **b, t_node *cheapest)
{
	while (cheapest->cost.ra > 0)
	{
		ra(a);
		cheapest->cost.ra--;
	}
	while (cheapest->cost.rb > 0)
	{
		rb(b);
		cheapest->cost.rb--;
	}
	while (cheapest->cost.rra > 0)
	{
		rra(a);
		cheapest->cost.rra--;
	}
	while (cheapest->cost.rrb > 0)
	{
		rrb(b);
		cheapest->cost.rrb--;
	}
}
