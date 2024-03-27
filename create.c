/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:11:04 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:12:51 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**makearray(int argc, char **argv)
{
	char	**argv_replace;
	int		i;

	i = 0;
	argv_replace = malloc(sizeof(char *) * argc);
	if (!argv_replace)
		return (NULL);
	while (i < argc - 1)
	{
		argv_replace[i] = ft_strdup(argv[i + 1]);
		if (!argv_replace[i])
		{
			free_array(argv_replace);
			return (NULL);
		}
		i++;
	}
	argv_replace[i] = NULL;
	return (argv_replace);
}

t_node	*ft_init_list(int argcount, char **arg_arr)
{
	int		i;
	t_node	*temp;
	t_node	*head;
	t_node	*last;

	
	i = 0;
	head = ft_dlstnew(ft_atol(arg_arr[i++]));
	temp = head;
	while (arg_arr[i] && i < argcount)
	{
		last = temp;
		temp = ft_dlstnew(ft_atol(arg_arr[i++]));
		if (!temp)
		{
			(ft_dlstclear(&head));
			return (NULL);
		}
		last->next = temp;
		temp->prev = last;
	}
	temp->next = NULL;
	return (head);
}

t_node	*ft_dlstnew(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->x = content;
	new->pos = 0;
	new->above_mid = 0;
    new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
