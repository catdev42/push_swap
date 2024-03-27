/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:33:39 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:35:56 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_both(t_node **stack_a, t_node **stack_b, t_node *target,
		t_node *cheapest)
{
	while (*stack_a != target && *stack_b != cheapest && *stack_a && *stack_b)
	{
		write(1, "rr\n", 3);
		first_to_last(stack_a);
		first_to_last(stack_b);
	}
	return (1);
}

int	reverse_both(t_node **stack_a, t_node **stack_b, t_node *target,
		t_node *cheapest)
{
	while (*stack_a != target && *stack_b != cheapest && *stack_a && *stack_b)
	{
		write(1, "rrr\n", 4);
		last_to_first(stack_a);
		last_to_first(stack_b);
	}
	return (1);
}

int	rotate_a(t_node **stack_a, t_node *target)
{
	if (target->above_mid)
	{
		while (*stack_a != target)
		{
			write(1, "ra\n", 3);
			first_to_last(stack_a);
		}
	}
	else
	{
		while (*stack_a != target)
		{
			write(1, "rra\n", 4);
			last_to_first(stack_a);
		}
	}
	return (1);
}

int	rotate_b(t_node **stack_b, t_node *cheapest)
{
	if (cheapest->above_mid)
	{
		while (*stack_b != cheapest)
		{
			write(1, "rb\n", 3);
			first_to_last(stack_b);
		}
	}
	else
	{
		while (*stack_b != cheapest)
		{
			write(1, "rrb\n", 4);
			last_to_first(stack_b);
		}
	}
	return (1);
}
