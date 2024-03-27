/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:37:26 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:55:03 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;
	int		la;
	int		lb;

	la = stack_len(stack_a);
	lb = stack_len(stack_b);
	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		while (a)
		{
			if (b->target == a && a->above_mid && b->above_mid)
				b->cost = a->pos + b->pos - bonus(a, b, la, lb);
			else if (b->target == a && a->above_mid && !b->above_mid)
				b->cost = a->pos + (lb - b->pos);
			else if (b->target == a && !a->above_mid && b->above_mid)
				b->cost = (la - a->pos) + b->pos;
			else if (b->target == a && !a->above_mid && !b->above_mid)
				b->cost = (la - a->pos) + (lb - b->pos) - bonus(a, b, la, lb);
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
	int		target_num;

	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		target_num = INT_MAX;
		b->target = NULL;
		while (a)
		{
			if (a->x > b->x && a->x < target_num)
			{
				target_num = a->x;
				b->target = a;
			}
			a = a->next;
		}
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
