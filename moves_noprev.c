/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_noprev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:46:38 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/26 02:51:00 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*temp_move;
	t_node	*temp_newhead;

	if (!stack_from || !*stack_from)
	{
		ft_printf("The from stack is empty, nothing more to push");
		return (0);
	}
	temp_move = *stack_from;
	// temp_move->prev = NULL;
	temp_newhead = (*stack_from)->next;
	// temp_newhead->prev = NULL;
	if (stack_from && stack_to)
	{
		if (*stack_to)
			temp_move->next = *stack_to;
		else
			temp_move->next = NULL;
		// if (stack_to && *stack_to)
		// (*stack_to)->prev = temp_move;
		*stack_to = temp_move;
		*stack_from = temp_newhead;
	}
	return (1);
}

int	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack)
	{
		ft_printf("nothing to swap, stack empty (error)");
		return (0);
	}
	first = *stack;
	second = (*stack)->next;
	// temp = first;
	first->next = second->next;
	// first->prev = second;
	second->next = first;
	// second->prev = NULL;
	*stack = second;
	return (1);
}

int	first_to_last(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*oldlast;

	if (!*stack || !stack)
	{
		ft_printf("nothing to swap, stack empty(error)");
		return (0);
	}
	first = *stack;
	second = (*stack)->next;
	oldlast = *stack;
	while (oldlast->next)
		oldlast = oldlast->next;
	oldlast->next = first;
	first->next = NULL;
	// newlast = templast->next;
	// newlast->next = NULL;
	// newlast->prev = templast;
	*stack = second;
	// newstart->prev = NULL;
	return (1);
}

int	last_to_first(t_node **stack)
{
	t_node *last;
    t_node *newlast;

	// t_node	*tmp;
	// tmp = *stack;
	if (!*stack || !stack)
	{
		ft_printf("nothing to swap, stack is empty (error)");
		return (0);
	}
	last = *stack;
	while (last->next->next)
		last = last->next;
    newlast = last;
    last = last->next;
	
	// newstart->prev->next = NULL;
	last->next = *stack;
    newlast->next = NULL;
	*stack = last;
    
	// newstart->next->prev = newstart;
	return (1);
}