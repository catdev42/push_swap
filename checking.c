/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:10:54 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:35:08 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->x > tmp->next->x)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_checkarray(int arg_count, char **arr)
{
	int	i;
	int	k;
	int	length;

	i = 0;
	while (arr[i] && i < arg_count)
	{
		length = ft_strlen(arr[i]) + 1;
		if (length > 11)
			return (0);
		k = 0;
		while (arr[i][k])
		{
			if (k == 0 && (arr[i][k] == '+' || arr[i][k] == '-'))
				k++;
			else if (k != 0 && !ft_isdigit(arr[i][k]))
				return (0);
			else
				k++;
		}
		if (!ft_checkdup(arg_count, arr))
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkdup(int arg_count, char **arr)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	while (arr[i] && i < arg_count)
	{
		length = ft_strlen(arr[i]) + 1;
		j = 0;
		while (arr[j])
		{
			if (i != j && !ft_strncmp(arr[i], arr[j], length))
				return (0);
			j++;
		}
		if (ft_atol(arr[i]) > INT_MAX || ft_atol(arr[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	stack_len(t_node **stack)
{
	int		i;
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
	int		len;
	int		i;
	t_node	*tmp;

	len = stack_len(stack);
	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		if (i < (len + 1) / 2)
			tmp->above_mid = 1;
		else
			tmp->above_mid = 0;
		tmp = tmp->next;
		i++;
	}
	return (1);
}
