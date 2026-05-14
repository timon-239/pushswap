/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:03:41 by tireis           #+#    #+#              */
/*   Updated: 2026/05/14 12:43:47 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack
{
	int value;
	int stack;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
int	ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);
t_stack *ft_stacknew(int value);
void	ft_stack_sa(t_stack **stack);
void	ft_freestack(t_stack **stack);




#endif
