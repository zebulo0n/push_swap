/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:18:21 by zoeschne          #+#    #+#             */
/*   Updated: 2025/07/03 15:47:03 by zoeschne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cost
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	int				total;
}					t_cost;

typedef struct s_node
{
	int				nb;
	int				index;
	int				is_lis;
	int				current;
	struct s_cost	cost;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/// PARSING
int					init_stack(t_node **a, char **av);
void				create_node(t_node **stack, int nb);
long				ft_atol(char *str);
t_node				*get_last(t_node *node);
char				**ft_split(char *str);
int					get_index(t_node *stack, int nb);

/// ERRORS HANDLING
int					syntax_check(char *str);
int					duplicate_check(t_node **stack);
int					overflow_check(long nb);

/// COMMANDS
void				swap(t_node **stack);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				swap_a_b(t_node **a, t_node **b);

void				push(t_node **src, t_node **dest);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);

void				rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rotate_a_b(t_node **a, t_node **b);

void				reverse_rotate(t_node **stack);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
void				reverse_rotate_a_b(t_node **a, t_node **b);

void				exec_rr_rrr(t_node **a, t_node **b, t_node *cheapest);
void				exec_ra_rb_rra_rrb(t_node **a, t_node **b,
						t_node *cheapest);

/// ALGORITHM
void				sort_three(t_node **stack);
void				exec_sort(t_node **a, t_node **b);
void				sort_stack(t_node **a, t_node **b);

/// LONGEST INCREASING SUBSEQUENCE
void				lis_sort(t_node **a, t_node **b);
void				init_lis(t_node **stack);
int					*node_to_array(t_node **stack);
int					find_lis(int arr[], int len, int **seq);
void				note_lis(int *seq, t_node **stack, int lis_len);

int					init_lis_arrays(int len, int **lis, int **prev);
int					calculate_lis(int arr[], int len, int lis[], int prev[]);
int					construct_lis(int arr[], int max[], int prev[], int **seq);
int					max_len(int len, int *arr);

/// GREEDY ALGORITHM
t_node				*calculate_cheapest(t_node **a, t_node **b);
void				calculate_cost(t_node *base, t_node **a, t_node **b);
t_node				*find_target(t_node *base, t_node **a);
void				base_on_top(t_node *base, t_node **b);
void				target_on_top(t_node *base, t_node *target, t_node **a);

void				set_current(t_node **a, t_node **b);
void				optimize_cost(t_node *base);
void				calculate_total(t_node *base);
void				reset_cost(t_node *node);
t_node				*find_min_index(t_node **a);

/// UTILS
int					stack_len(t_node *stack);
int					is_sorted(t_node *stack);
int					find_max(t_node *stack);
int					max(int a, int b);
void				free_stack(t_node **stack);
void				free_split(char **args);
int					find_min(t_node **a);
int					is_only_space(char *str);
int					is_space(char c);

#endif