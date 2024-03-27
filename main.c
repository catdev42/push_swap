/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/26 03:32:04 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arg_arr;
	int		arg_count;

	stack_a = NULL;
	stack_b = NULL;
	arg_arr = NULL;
	if (argc < 2)
		return (ft_clean(arg_arr, &stack_a, &stack_b, 1));
	if (argc == 2)
		arg_arr = ft_split(argv[1], ' ');
	else
		arg_arr = makearray(argc, argv);
	if (!arg_arr)
		return (2);
	arg_count = ft_matrixlen(arg_arr);
	if (!ft_checkarray(arg_count, arg_arr))
		return (ft_clean(arg_arr, &stack_a, &stack_b, 2));
	stack_a = ft_init_list(arg_count, arg_arr);
	if (!stack_a || is_sorted(&stack_a))
		return (ft_clean(arg_arr, &stack_a, &stack_b, 3));
	ft_sort(&stack_a, &stack_b, arg_count);
	// t_node	*tmp;
	// tmp = stack_a;
	// ft_printf("Printing the stack to check \n");
	// while (tmp)
	// {
	// 	ft_printf("%i \n", tmp->x);
	// 	tmp = tmp->next;
	// }
	ft_clean(arg_arr, &stack_a, &stack_b, 0);
	// free_array(arg_arr);
	return (0);
}

// CHECK IT

// 	t_node *tmp;
// tmp = *stack-a;
// 	ft_printf("Printing the stack to check \n");

// while (tmp)
// {
// 	ft_printf("%i \n", tmp->x);
// 	tmp = tmp->nextl
// }

// int	is_sorted(t_node **stack_a)
// {
// 	t_node	*tmp;

// 	tmp = *stack_a;
// 	tmp = tmp->next;
// 	while (tmp)
// 	{
// 		if (tmp->x < tmp->prev->x)
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

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

// main
// FOR CHECKING
// swap(&stack_a);
// ft_printf("now printing %i \n", stack_a->x);
// ft_printf("initializes stack a %i \n", stack_a->next->x);
// ft_printf("prints last %i \n", stack_a->next->next->x);
// // ft_printf("should segv %i \n", stack_a->next->next->next->x);

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
