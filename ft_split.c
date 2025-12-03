/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:17:26 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/02 22:19:58 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' || c == '\0')
		return (1);
	else
		return (0);
}

int	word_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_space(str[i]) == 0 && is_space(str[i + 1]) == 1)
			count++;
		i++;
	}
	return (count + 1);
}

char	*fill_word(char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		start;
	char	**array;

	i = 0;
	j = 0;
	start = 0;
	if (is_only_space(str) == 1)
		return (NULL);
	array = malloc(sizeof(char *) * (word_count(str) + 1));
	if (!array)
		return (NULL);
	array[j++] = "a.out\0";
	while (str[i] && j < word_count(str))
	{
		while (is_space(str[i]) == 1)
			i++;
		start = i;
		while (is_space(str[i]) == 0)
			i++;
		array[j++] = fill_word(str, start, i);
	}
	array[j] = NULL;
	return (array);
}

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 1;
	while (args[i])
		free(args[i++]);
	free(args);
}
