/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:50 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 17:29:37 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_sort(t_node **a, t_node **b)
{
	int	i;
	int	len;

	len = stack_len(*a);
	init_lis(a);
	i = 0;
	while (i < len)
	{
		if ((*a)->is_lis == 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

void	init_lis(t_node **stack)
{
	int	*array;
	int	len;
	int	lis_len;
	int	*lis_sequence;

	lis_sequence = NULL;
	array = node_to_array(stack);
	len = stack_len(*stack);
	lis_len = find_lis(array, len, &lis_sequence);
	note_lis(lis_sequence, stack, lis_len);
	free(array);
}

int	*node_to_array(t_node **stack)
{
	t_node	*tmp;
	int		*array;
	int		i;

	tmp = *stack;
	i = stack_len(tmp);
	array = malloc(sizeof(int) * i);
	if (!array)
		return (0);
	i = 0;
	while (tmp)
	{
		array[i] = tmp->index;
		i++;
		tmp = tmp->next;
	}
	return (array);
}

int	find_lis(int arr[], int len, int **seq)
{
	int	*lis;
	int	*prev;
	int	max[2];
	int	result;

	lis = NULL;
	prev = NULL;
	if (!init_lis_arrays(len, &lis, &prev))
		return (0);
	max[0] = calculate_lis(arr, len, lis, prev);
	max[1] = lis[max[0]];
	result = construct_lis(arr, max, prev, seq);
	free(lis);
	free(prev);
	return (result);
}

void	note_lis(int *seq, t_node **stack, int lis_len)
{
	int		i;
	t_node	*tmp;

	tmp = *stack;
	i = 0;
	while (tmp && i < lis_len)
	{
		if (tmp->index == seq[i])
		{
			tmp->is_lis = 1;
			i++;
		}
		tmp = tmp->next;
	}
	free(seq);
}
