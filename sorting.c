/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:32:11 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:40:53 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_node **stack_a, t_node **stack_b, int arg_count)
{
	if (arg_count == 2)
		if (!sort_two(stack_a))
			return (0);
	if (arg_count == 3)
		if (!sort_three(stack_a))
			return (0);
	if (arg_count > 3)
		if (!sort_more(stack_a, stack_b))
			return (0);
	return (1);
}

int	sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_address;
	int		size;

	min_address = find_min(stack_a);
	p_to_b(stack_a, stack_b);
	size = stack_len(stack_a);
	if (size == 3)
		sort_three(stack_a);
	else
		write(1, "not 3\n", 6);
	while (*stack_b)
	{
		actual_sorting(stack_a, stack_b);
	}
	index_stack(stack_a);
	rotate_a(stack_a, min_address);
	return (1);
}

int	p_to_b(t_node **stack_a, t_node **stack_b)
{
	while (stack_len(stack_a) > 3)
	{
		if (write(1, "pb\n", 3) == -1)
			return (0);
		push(stack_a, stack_b);
	}
	return (1);
}

void	actual_sorting(t_node **stack_a, t_node **stack_b)
{
	index_stack(stack_a);
	index_stack(stack_b);
	find_target(stack_a, stack_b);
	calc_cost(stack_a, stack_b);
	move_to_target(stack_a, stack_b);
}

int	move_to_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = find_cheapest(stack_b);
	target = cheapest->target;
	if (cheapest->above_mid && target->above_mid)
		rotate_both(stack_a, stack_b, target, cheapest);
	else if (!cheapest->above_mid && !target->above_mid)
		reverse_both(stack_a, stack_b, target, cheapest);
	index_stack(stack_a);
	rotate_a(stack_a, target);
	index_stack(stack_b);
	rotate_b(stack_b, cheapest);
	push(stack_b, stack_a);
	if (write(1, "pa\n", 3) == -1)
		return (0);
	return (1);
}

/*
// push_all_to_b(stack_a, stack_b);


int	push_all_to_b(t_node **stack_a, t_node **stack_b)
{
	int		hold_in_a;
	t_node	*min_address;
	int		start_holding;

	start_holding = 0;
	min_address = find_min(stack_a);
	hold_in_a = min_address->x;
	while (!is_sorted(stack_a) && stack_len(stack_a) > 3)
	{
		if ((*stack_a)->x == hold_in_a)
			start_holding = 1;
		if (start_holding == 1 && (*stack_a)->next->x > hold_in_a)
			hold_in_a = ((*stack_a)->next->x);
		if (start_holding == 1 && (*stack_a)->x == hold_in_a)
		{
			if (write(1, "ra\n", 3) == -1)
				return (0);
			first_to_last(stack_a);
		}
		else if (start_holding == 0 || (*stack_a)->x != hold_in_a)
		{
			if (write(1, "pb\n", 3) == -1)
				return (0);
			push(stack_a, stack_b);
		}
		// else if (start_holding == 1 && tmp->x == hold_in_a)
		// 	tmp =
	}
	return (1);
}
*/