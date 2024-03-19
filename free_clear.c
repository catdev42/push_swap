/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:59:16 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/19 21:31:27 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_fail(void)
{
	// if (errornum == 0)
	write(2, "Error\n", 6);
	// ft_putstr_fd("Too few arguments", 2)
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

// char	**ft_free_split_ps(char **arr, int index)
// {
// 	while (index > 0)
// 	{
// 		free(arr[index]);
// 		index--;
// 	}
// 	if (index == 0)
// 		free(arr[0]);
// 	free(arr);
// 	return (NULL);
// }

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