/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:55:50 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/03 17:33:33 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "../push_swap.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buf
{
	char			*buf;
	struct s_buf	*next;
}					t_buf;

char				*get_next_line(int fd);
void				content_to_node(int fd, t_buf **stash);
void				buf_to_node(t_buf **stash, char *buf, int nbytes_read);
void				node_to_line(t_buf *stash, char **line);
void				clean_output(t_buf **stash);
int					is_newline(t_buf *stash);
t_buf				*ft_lstlast(t_buf *lst);
void				malloc_line_size(char **line, t_buf *stash);
void				free_stash(t_buf *stash);
int					ft_strlen(const char *str);

int					is_empty(t_node *stack);
int					exec_instruction(char *mov, t_node **a, t_node **b);
int					read_instructions(t_node **a, t_node **b);
int					ft_strcmp(char *s1, char *s2);
void				free_all(t_node *a, t_node *b, int ac, char **av);

#endif
