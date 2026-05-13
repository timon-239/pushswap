/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/13 16:03:41 by tireis           #+#    #+#              */
/*   Updated: 2026/05/13 16:20:07 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typef struct s_stack
{
	int value;
	int stack;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int	ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);




#endif
