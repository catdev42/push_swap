/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:32:11 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/23 22:12:28 by myakoven         ###   ########.fr       */
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

int	sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_address;

	min_address = find_min(stack_a);
	push_all_to_b(stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	while (*stack_b)
	{
		index_stack(stack_a);
		index_stack(stack_b);
		find_target(stack_a, stack_b);
		calc_cost(stack_a, stack_b);
		move_to_target(stack_a, stack_b);
	}
	// to know how many times to rotate?
	calc_current_pos(stack_a);
	min_to_top(stack_a);
}

int	calc_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;
	int		len_a;
	int		len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		while (a)
		{
			if (b->target == a && a->above_mid && b->above_mid)
				b->cost = a->pos + b->pos - bonus(a, b, len_a, len_b);
			else if (b->target == a && a->above_mid && !b->above_mid)
				b->cost = a->pos + (len_b - b->pos);
			else if (b->target == a && !a->above_mid && b->above_mid)
				b->cost = (len_a - a->pos) + b->pos;
			else if (b->target == a && !a->above_mid && !b->above_mid)
				b->cost = (len_a - a->pos) + (len_b - b->pos) - bonus(a, b,
						len_a, len_b);
			a = a->next;
		}
		b = b->next;
	}
}

int	bonus(t_node *a, t_node *b, int len_a, int len_b)
{
	int	bon;

	// int	len_a;
	// int	len_b;
	// len_a = stack_len(stack_a);
	// len_b = stack_len(stack_b);
	bon = 0;
	if (a->above_mid == 1 && b->above_mid == 1)
	{
		bon = a->pos;
		if (a->pos > b->pos)
			bon = b->pos;
	}
	else if (a->above_mid == 0 && b->above_mid == 0)
	{
		bon = len_a - a->pos;
		if (len_b - b->pos < bon)
			bon = len_b - b->pos;
	}
	return (bon);
}

int	push_all_to_b(t_node **stack_a, t_node **stack_b)
{
	int		hold_in_a;
	t_node	*min_address;
	int		start_holding;
	t_node	*tmp;

	tmp = *stack_a;
	start_holding = 0;
	min_address = find_min(stack_a);
	hold_in_a = min_address->x;
	while (!is_sorted(stack_a) && stack_len(stack_a) > 3)
	{
		if ((tmp)->x == hold_in_a)
			start_holding = 1;
		if (stack_len(stack_a) > 3 && (tmp)->x == hold_in_a)
		{
			if (write(1, "ra", 2) == -1)
				return (0);
			first_to_last(stack_a);
		}
		if (start_holding == 1 && tmp->next->x > hold_in_a)
			hold_in_a = (tmp->next->x);
		if (start_holding == 0 || (tmp)->x != hold_in_a)
		{
			if (write(1, "pb", 2) == -1)
				return (0);
			push(stack_a, stack_b);
		}
	}
	return (1);
}

int	stack_len(t_node **stack)
{
	size_t	i;
	t_node	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	index_stack(t_node **stack)
{
	t_node	*tmp;
	int		i;
	int		len;

	len = stack_len(stack);
	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		if (i < (len + 1) / 2)
			tmp->above_mid = 1;
		else
			tmp->above_mid = 0;
		i++;
	}
	return (1);
}

int	find_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;
	t_node	*target_address;
	int		target_num;

	a = *stack_a;
	b = *stack_b;
	// if (write(1, "sa", 2) == -1)
	// 		return (0); WHY IS THIS HERE???
	while (b)
	{
		a = *stack_a;
		target_num == INT_MAX;
		b->target = NULL;
		while (a)
		{
			if (a->x > b->x && a->x < target_num)
			{
				target_num = a->x;
				target_address = a;
			}
		}
		b->target = target_address;
		if (b->target == NULL)
			b->target = find_min(*stack_a);
		b = b->next;
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

t_node	*find_cheapest(t_node **stack)
{
	int		cheap_cost;
	t_node	*cheapest_node;
	t_node	*tmp;

	cheap_cost = INT_MAX;
	tmp = *stack;
	cheapest_node = NULL;
	while (tmp)
	{
		if (tmp->cost < cheap_cost)
		{
			cheapest_node = tmp;
			cheap_cost = tmp->cost;
		}
		tmp = tmp->next;
	}
	return (cheapest_node);
}
