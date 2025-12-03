/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:40 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 16:24:10 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_node **stack, char **av)
{
	long	nb;
	int		i;
	t_node	*tmp;

	i = 0;
	while (av[i])
	{
		if (!syntax_check(av[i]))
			return (0);
		nb = atol(av[i]);
		if (!overflow_check(nb))
			return (0);
		create_node(stack, (int)nb);
		i++;
	}
	if (!duplicate_check(stack))
		return (0);
	tmp = *stack;
	while (tmp)
	{
		tmp->index = get_index(*stack, tmp->nb);
		tmp->is_lis = 0;
		tmp = tmp->next;
	}
	return (1);
}

int	get_index(t_node *stack, int nb)
{
	int		index;
	t_node	*tmp;

	tmp = stack;
	index = 0;
	while (stack)
	{
		if (stack->nb < nb)
			index++;
		stack = stack->next;
	}
	return (index);
}

void	create_node(t_node **stack, int nb)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack);
		return ;
	}
	new_node->next = NULL;
	new_node->nb = nb;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = get_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

long	ft_atol(char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
	}
	return (nb * sign);
}

t_node	*get_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node != NULL && node->next)
		node = node->next;
	return (node);
}
