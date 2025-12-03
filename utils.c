/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:46 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 16:32:26 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	is_sorted(t_node *stack)
{
	int	prev_num;

	prev_num = stack->nb;
	while (stack)
	{
		if (stack->nb < prev_num)
			return (0);
		prev_num = stack->nb;
		stack = stack->next;
	}
	return (1);
}

int	find_max(t_node *stack)
{
	int	prev_num;

	prev_num = stack->nb;
	while (stack)
	{
		if (stack->nb > prev_num)
			prev_num = stack->nb;
		stack = stack->next;
	}
	return (prev_num);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}
