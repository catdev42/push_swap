/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:46:38 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/09 18:16:42 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* IS IT BETTER TO RETURN THE NEW STACK POINTER???*/

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
	temp_newhead = temp_move->next;
	if (stack_from && stack_to)
	{
		if (*stack_to)
			temp_move->next = *stack_to;
		else
			temp_move->next = NULL;
		if (stack_to && *stack_to)
			(*stack_to)->prev = temp_move;
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
	first->next = first->next->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
	return (1);
}

int	first_to_last(t_node **stack)
{
	t_node	*templast;
	t_node	*newstart;

	if (!*stack || !stack)
	{
		ft_printf("nothing to swap, stack empty(error)");
		return (0);
	}
	newstart = (*stack)->next;
	templast = *stack;
	while (templast->next)
		templast = templast->next;
	templast->next = *stack;
	templast->next->next = NULL;
	*stack = newstart;
	return (1);
}

int	last_to_first(t_node **stack)
{
	t_node	*newstart;

	if (!*stack || !stack)
	{
		ft_printf("nothing to swap, stack is empty (error)");
		return (0);
	}
	newstart = *stack;
	while (newstart->next)
		newstart = newstart->next;
	newstart->prev->next = NULL;
	newstart->next = *stack;
	*stack = newstart;
	return (1);
}
