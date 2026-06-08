/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:03:41 by tireis           #+#    #+#              */
/*   Updated: 2026/06/08 15:48:58 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
typedef enum e_mode
{
	MODE_AUTO,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_ADAPTIVE,
}					t_mode;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
// UTILS
void				ft_stackadd_back(t_stack **stack, t_stack *new);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
int					ft_stacksize(t_stack *stack);
t_stack				*ft_stacklast(t_stack *stack);
t_stack				*ft_stacknew(int value);
void				ft_stack_sa(t_stack **stack);
void				ft_freestack(t_stack **stack);
int					ft_strcmp(char *s1, char *s2);
// BASICS
void				ft_swap_logic(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ft_push_logic(t_stack **dst, t_stack **src);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				reverse_ro_logic(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				ft_rotate_logic(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
// rest
int					ft_atoi(const char *str);
void				sort_simple(t_stack **a, t_stack **b);
int					is_num(char *str);
int					has_duplicates(t_stack *stack);
void				assign_index(t_stack *a);
int					is_sorted(t_stack *a);
// simple
void				sort_three(t_stack **a);
int					get_pos_of_index(t_stack *stack, int target_index);
void				push_min_to_b(t_stack **a, t_stack **b, int target_index);
void				sort_simple(t_stack **a, t_stack **b);
// medium
void				sort_medium(t_stack **a, t_stack **b);
void				push_to_b_in_chunks(t_stack **a, t_stack **b);
static int					get_chunk_size(int size);
int					get_max_index_value(t_stack *stack);
int					disorder_metric(t_stack *a);
// complex
void				sort_complex(t_stack **a, t_stack **b);
int					get_max_bits(int max_index);

#endif
