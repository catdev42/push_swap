/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:46:38 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:40:41 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*temp_move;
	t_node	*temp_newhead;

	if (!stack_from || !*stack_from)
	{
		return (0);
	}
	temp_move = *stack_from;
	temp_newhead = (*stack_from)->next;
	if (stack_from && stack_to)
	{
		if (*stack_to)
			temp_move->next = *stack_to;
		else
			temp_move->next = NULL;
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
		return (0);
	}
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
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
		return (0);
	}
	first = *stack;
	second = (*stack)->next;
	oldlast = *stack;
	while (oldlast->next)
		oldlast = oldlast->next;
	oldlast->next = first;
	first->next = NULL;
	*stack = second;
	return (1);
}

int	last_to_first(t_node **stack)
{
	t_node	*last;
	t_node	*newlast;

	if (!*stack || !stack)
	{
		return (0);
	}
	last = *stack;
	while (last->next->next)
		last = last->next;
	newlast = last;
	last = last->next;
	last->next = *stack;
	newlast->next = NULL;
	*stack = last;
	return (1);
}
