/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:23:33 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/03 17:35:17 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "checker.h"

int	main(int ac, char *av[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		if (ac == 2 && !av[1][0])
			write(2, "Error\n", 6);
		return (0);
	}
	else if (ac == 2)
		av = ft_split(av[1]);
	if (!av || !init_stack(&a, av + 1) || !read_instructions(&a, &b))
	{
		free_all(a, b, ac, av);
		get_next_line(-1);
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(a, b, ac, av);
}

int	read_instructions(t_node **a, t_node **b)
{
	char	*command;

	command = get_next_line(0);
	while (command != NULL)
	{
		if (!exec_instruction(command, a, b))
		{
			free(command);
			return (0);
		}
		free(command);
		command = get_next_line(0);
	}
	return (1);
}

int	exec_instruction(char *mov, t_node **a, t_node **b)
{
	if (ft_strcmp(mov, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(mov, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(mov, "ss\n") == 0)
		swap_a_b(a, b);
	else if (ft_strcmp(mov, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(mov, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(mov, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(mov, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(mov, "rr\n") == 0)
		rotate_a_b(a, b);
	else if (ft_strcmp(mov, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(mov, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(mov, "rrr\n") == 0)
		reverse_rotate_a_b(a, b);
	else
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] != '\0')
		x++;
	return (s1[x] - s2[x]);
}

void	free_all(t_node *a, t_node *b, int ac, char **av)
{
	free_stack(&a);
	free_stack(&b);
	if (ac == 2)
		free_split(av);
}
