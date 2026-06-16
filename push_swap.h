/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:03:41 by tireis           #+#    #+#              */
/*   Updated: 2026/06/15 18:59:45 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
#

typedef enum e_mode
{
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

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_bench;

typedef struct s_config
{
	t_mode			mode;
	int				bench;
}					t_config;

// BENCH
void				bench_init(t_bench *b);
void				print_bench(t_bench *b, float disorder, t_mode mode);
// UTILS
void				ft_stackadd_back(t_stack **stack, t_stack *new);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
int					ft_stacksize(t_stack *stack);
t_stack				*ft_stacklast(t_stack *stack);
t_stack				*ft_stacknew(int value);
void				ft_stack_sa(t_stack **stack);
void				ft_freestack(t_stack **stack);
int					ft_strcmp(char *s1, char *s2);
int					parse_token(char *str, t_stack **a);
// BASICS
void				ft_swap_logic(t_stack **stack);
void				sa(t_stack **stack_a, t_bench *bench);
void				sb(t_stack **stack_b, t_bench *bench);
void				ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void				ft_push_logic(t_stack **dst, t_stack **src);
void				pa(t_stack **a, t_stack **b, t_bench *bench);
void				pb(t_stack **a, t_stack **b, t_bench *bench);
void				reverse_ro_logic(t_stack **stack);
void				rra(t_stack **a, t_bench *bench);
void				rrb(t_stack **b, t_bench *bench);
void				rrr(t_stack **a, t_stack **b, t_bench *bench);
void				ft_rotate_logic(t_stack **stack);
void				ra(t_stack **a, t_bench *bench);
void				rb(t_stack **b, t_bench *bench);
// rest
long				ft_atol(const char *str);
char				**ft_split(const char *s, char c);
char				**ft_freeall(char **arr, size_t i);
size_t				ft_strlen(const char *str);
int					is_num(char *str);
int					has_duplicates(t_stack *stack);
void				assign_index(t_stack *a);
int					is_sorted(t_stack *a);
// simple
void				sort_three(t_stack **a, t_bench *bench);
int					get_pos_of_index(t_stack *stack, int target_index);
void				push_min_to_b(t_stack **a, t_stack **b, int target_index,
						t_bench *bench);
void				sort_simple(t_stack **a, t_stack **b, t_bench *bench);
// medium
void				sort_medium(t_stack **a, t_stack **b, t_bench *bench);
void				push_to_b_in_chunks(t_stack **a, t_stack **b,
						t_bench *bench);
int					get_max_index_value(t_stack *stack);
float				disorder_metric(t_stack *a);
// complex
void				sort_complex(t_stack **a, t_stack **b, t_bench *bench);
int					get_max_bits(int max_index);

#endif
