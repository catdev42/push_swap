/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:11:09 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:39:16 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_clean(arg_arr, &stack_a, &stack_b, 0);
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

/*
t_node	*tmp;
	tmp = stack_a;
	ft_printf("Printing the stack to check \n");
	while (tmp)
	{
		ft_printf("%i \n", tmp->x);
		tmp = tmp->next;
	}
*/
