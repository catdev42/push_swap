/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_pers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:02:20 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:56:03 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
