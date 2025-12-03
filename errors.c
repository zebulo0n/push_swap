/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:14 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 22:39:29 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	duplicate_check(t_node **stack)
{
	t_node	*outer;
	t_node	*inner;

	outer = *stack;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->nb == inner->nb)
				return (0);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (1);
}

int	overflow_check(long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	else
		return (1);
}

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
