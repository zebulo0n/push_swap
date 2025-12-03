/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:01 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/03 16:21:35 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!av || !init_stack(&a, av + 1))
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (!is_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (ac == 2)
		free_split(av);
}
