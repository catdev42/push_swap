/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/09 23:45:04 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

int	main(int argc, char **argv)
{
	// t_node	**head_a;
	t_node	*stack_a;
	char	**argv_replace;

	// t_node	** stack_b;
	stack_a = NULL;
	// head_a = &stack_a;
	// stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		argv_replace = ft_split(argv[1], ' ');
	else
		argv_replace = makearray(argc, argv);
	if (!argv_replace)
		return (1);
	if (!ft_checkarray(argc, argv_replace))
		return ((long)ft_free_split_ps(argv_replace, (ft_matrixlen(argv) - 1)));
	stack_a = ft_init_list(argc, argv_replace);
	swap(&stack_a);
	ft_printf("now printing %i \n", stack_a->x);
	ft_printf("initializes stack a %i \n", stack_a->next->x);
	ft_printf("prints last %i \n", stack_a->next->next->x);
	// ft_printf("should segv %i \n", stack_a->next->next->next->x);
	if (!stack_a)
		return (2);
	// TO DO
	// ft_index_list(stack_a);
	ft_free_split_ps(argv_replace, (ft_matrixlen(argv_replace) - 1));
	return (0);
}

int	ft_checkarray(int argc, char **arr)
{
	int	i;
	int	j;

	if (argc == 2)
		argc = ft_matrixlen(arr);
	i = 0;
	j = 0;
	while (arr[j])
	{
		if (i != j && !ft_strncmp(arr[i], arr[j], ft_strlen(arr[i]) + 1))
			return (error_fail());
		j++;
	}
	while (arr[i] && i < argc)
	{
		if (ft_atol(arr[i]) > INT_MAX || ft_atol(arr[i]) < INT_MIN)
			return (error_fail());
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				return (error_fail());
			j++;
		}
		i++;
	}
	return (1);
}

int	error_fail(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	ft_matrixlen(char **arr)
{
	int	i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/******THIS NEEDS A COUNT LIMITER!!!*******/
t_node	*ft_init_list(int argc, char **argv)
{
	int		i;
	t_node	*temp;
	t_node	*head;
	t_node	*last;

	// t_node	**stack_a_init;
	// stack_a_init = NULL;
	if (argc == 2)
		argc = ft_matrixlen(argv);
	i = 0;
	head = ft_dlstnew(ft_atoi(argv[i++]));
	// stack_a_init = &head;
	temp = head;
	while (argv[i] && i < argc)
	{
		last = temp;
		temp = ft_dlstnew(ft_atol(argv[i++]));
		if (!temp)
		{
			(ft_dlstclear(&head));
			return (NULL);
		}
		last->next = temp;
		temp->prev = last;
	}
	temp->next = NULL;
	// WHY IS THIS HERE?
	// temp = ft_dlstnew(ft_atoi(argv[i++]));
	// if (!temp)
	// 	ft_dlstclear(stack_a_init);
	// ft_dlstadd_back(stack_a_init, temp);
	return (head);
}

// int	ft_arrsize(char **arr)
// {
// 	int	i;

// 	if (!arr)
// 		return (0);
// 	i = 0;
// 	while (arr[i])
// 		i++;
// 	return (i);
// }
