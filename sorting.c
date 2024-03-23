/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:32:11 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/23 19:47:44 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_node **stack_a, t_node **stack_b, int arg_count)
{
	if (arg_count == 2)
		if (!sort_two(stack_a))
			return (0);
	if (arg_count == 3)
		if (!sort_three)
			return (0);
	if (arg_count > 3)
		if (!sort_big(stack_a, stack_b))
			return (0);
	return (1);
}

int	sort_two(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	if (write(1, "sa", 2) == -1)
		return (0);
	swap(stack);
	return (1);
}

int	sort_three(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (!is_sorted(stack))
	{
		if (tmp->x > tmp->next->x && tmp->x > tmp->next->next->x)
		{
			if (write(1, "ra", 2) == -1)
				return (0);
			first_to_last(stack);
		}
		else if (tmp->x < tmp->next->x && tmp->next->next->x < tmp->x)
		{
			if (write(1, "rra", 2) == -1)
				return (0);
			last_to_first(stack);
		}
		else
		{
			if (write(1, "sa", 2) == -1)
				return (0);
			swap(stack);
		}
		return (1);
	}
}

// TODO: FUNCTION FOR SORT MORE

/*
while there is more than 3 items in stack_a, push to stack b
Sort three in stack_a
while there are items in stack_b
{
	calc_positions(stack_a);
	calc_positions(stack_b);
	calc_targets;
	calc_cost;
	move_to_target;
}
calc_current_pos(stack_a); (may be unnecessary)
min_to_top(stack_a);
*/




int	find_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	t_node	*target_address;
	int		target_num;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		target_num == INT_MAX;
		tmp_b->target = NULL;
		while (tmp_a)
		{
			if (tmp_a->x > tmp_b->x && tmp_a->x < target_num)
			{
				target_num = tmp_a->x;
				target_address = tmp_a;
			}
		}
		tmp_b->target = target_address;
		if (tmp_b->target == NULL)
			tmp_b->target = find_min(*stack_a);
		tmp_b = tmp_b->next;
	}
}

t_node	*find_min(t_node *stack)
{
	int		smallest;
	t_node	*min_node;
	t_node	*tmp;

	if (!stack)
		return ((t_node *)error_fail());
	smallest = INT_MAX;
	tmp = stack;
	min_node = NULL;
	while (tmp)
	{
		if (tmp->x < smallest)
			min_node = tmp;
		tmp = tmp->next;
	}
	return (min_node);
}
