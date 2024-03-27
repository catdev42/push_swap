/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:32:11 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/26 03:29:41 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


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

int	sort_two(t_node **stack)
{
	if (write(1, "sa\n", 3) == -1)
		return (0);
	swap(stack);
	return (1);
}

int	sort_three(t_node **stack)
{
	t_node	*tmp;

	while (!is_sorted(stack))
	{
		tmp = *stack;
		if (tmp->x > tmp->next->x && tmp->x > tmp->next->next->x)
		{
			if (write(1, "ra\n", 3) == -1)
				return (0);
			first_to_last(stack);
		}
		else if (tmp->x < tmp->next->x && tmp->next->next->x < tmp->x)
		{
			if (write(1, "rra\n", 4) == -1)
				return (0);
			last_to_first(stack);
		}
		else
		{
			if (write(1, "sa\n", 3) == -1)
				return (0);
			swap(stack);
		}
	}
	return (1);
}

int	sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_address;
	int		size;

	min_address = find_min(stack_a);
	// push_all_to_b(stack_a, stack_b);
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

void	print_all(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		printf("ITEM %i, \n tmp->x = %i,\n tmp->pos = %i,\n tmp->above_min = %i,\n tmp->target = %p,\n tmp->cost = %i,\n tmp->prev = %p, \n tmp->next = %p \n", i, tmp->x, tmp->pos, tmp->above_mid,
			tmp->target, tmp->cost, tmp->prev, tmp->next);
		tmp = tmp->next;
		i++;
	}
	// swap(stack_a);
	// tmp = *stack_a;
	// i = 0;
	// while (tmp)
	// {
	// 	printf("ITEM %i, at address %p \n tmp->x = %i,\n tmp->pos =
	// %i,\n tmp->above_min = %i,\n tmp->target->x = %i,\n tmp->cost =
	// 		%i,\n tmp->prev = %p, \n tmp->next = %p", i, tmp,
	// 			tmp->x,
	// 			tmp->pos,
	// 			tmp->above_mid,
	// 			tmp->target->x,
	// 			tmp->cost,
	// 			tmp->prev,
	// 			tmp->next);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	// push(stack_a, stack_b);
	// tmp = *stack_a;
	// i = 0;
	// while (tmp)
	// {
	// 	printf("ITEM %i, at address %p \n tmp->x = %i,\n tmp->pos =
	// %i,\n tmp->above_min = %i,\n tmp->target->x = %i,\n tmp->cost =
	// %i,\n tmp->prev = %p, \n tmp->next = %p", i, tmp,
	// 			tmp->x,
	// 			tmp->pos,
	// 			tmp->above_mid,
	// 			tmp->target->x,
	// 			tmp->cost,
	// 			tmp->prev,
	// 			tmp->next);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	tmp = *stack_b;
	i = 0;
	printf("\n STACK B \n");
	while (stack_a != stack_b && tmp)
	{
		printf("ITEM %i, at address %p \n tmp->x = %i,\n tmp->pos = %i,\n tmp->above_min = %i,\n tmp->target->x = %i,\n tmp->cost = %i,\n tmp->prev = %p, \n tmp->next = %p \n", i, tmp, tmp->x,
			tmp->pos, tmp->above_mid, tmp->target->x, tmp->cost, tmp->prev,
			tmp->next);
		tmp = tmp->next;
		i++;
	}
}

/*
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

void	calc_cost(t_node **stack_a, t_node **stack_b)
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

int	find_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;
	t_node	*target_address;
	int		target_num;

	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		target_address = NULL;
		a = *stack_a;
		target_num = INT_MAX;
		b->target = NULL;
		while (a)
		{
			if (a->x > b->x && a->x < target_num)
			{
				target_num = a->x;
				target_address = a;
			}
			a = a->next;
		}
		b->target = target_address;
		if (b->target == NULL)
			b->target = find_min(stack_a);
		b = b->next;
	}
	return (1);
}

t_node	*find_min(t_node **stack)
{
	int		smallest;
	t_node	*min_node;
	t_node	*tmp;

	if (!stack || !*stack)
		return (NULL);
	smallest = INT_MAX;
	tmp = *stack;
	min_node = NULL;
	while (tmp)
	{
		if (tmp->x < smallest)
		{
			min_node = tmp;
			smallest = tmp->x;
		}
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
