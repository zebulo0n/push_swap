/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:43 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 22:39:15 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_len(int len, int *arr)
{
	int	i;
	int	max_len;

	max_len = 0;
	i = 0;
	while (i < len)
	{
		max_len = max(max_len, arr[i]);
		i++;
	}
	return (max_len);
}

int	init_lis_arrays(int len, int **lis, int **prev)
{
	int	i;

	*lis = malloc(sizeof(int) * len);
	*prev = malloc(sizeof(int) * len);
	if (!(*lis) || !(*prev))
		return (0);
	i = 0;
	while (i < len)
	{
		(*lis)[i] = 1;
		(*prev)[i] = -1;
		i++;
	}
	return (1);
}

int	calculate_lis(int arr[], int len, int lis[], int prev[])
{
	int	i;
	int	j;
	int	max_idx;

	i = 1;
	max_idx = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		if (lis[i] > lis[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	construct_lis(int arr[], int max[], int prev[], int **seq)
{
	int	max_length;
	int	current;
	int	i;

	max_length = max[1];
	current = max[0];
	*seq = malloc(sizeof(int) * max_length);
	if (!(*seq))
		return (0);
	i = max_length - 1;
	while (i >= 0)
	{
		(*seq)[i] = arr[current];
		current = prev[current];
		i--;
	}
	return (max_length);
}

int	find_min(t_node **a)
{
	t_node	*tmp;
	int		half_stack;
	int		i;

	tmp = *a;
	half_stack = stack_len(tmp) / 2;
	i = 0;
	while (tmp && i <= half_stack)
	{
		if (tmp->index == 0)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
