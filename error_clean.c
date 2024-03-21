/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:58:25 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/21 20:28:52 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_clean(char **arg_arr, t_node **stack_a, t_node **stack_b, int error)
{
	if (stack_a && *stack_a)
		ft_dlstclear(stack_a);
	if (stack_b && *stack_b)
		ft_dlstclear(stack_a);
	if (arg_arr)
		free_array(arg_arr);
	if (error)
	{
		error_fail();
		return (error);
	}
	return (0);
}

int	error_fail(void)
{
	write(2, "Error\n", 6);
	return (0);
}

t_node	**ft_dlstclear(t_node **lst)
{
	t_node	*tmp;
	t_node	*prev;

	if (!lst)
		return (NULL);
	tmp = *lst;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	*lst = NULL;
	return (NULL);
}
int	free_array(char **arr)
{
	int i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}