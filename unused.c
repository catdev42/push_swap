


/*
int	push_all_to_b(t_node **stack_a, t_node **stack_b)
{
	size_t	i;
	t_node	*tmp;
	t_node	*tmp;
	int		i;
	int		len;

	// int		hold_in_a;
	// t_node	*min_address;
	// int		start_holding;
	// t_node	*tmp;
	// tmp = *stack_a;
	// start_holding = 0;
	// min_address = find_min(stack_a);
	// hold_in_a = min_address->x;
	while (!is_sorted(stack_a) && stack_len(stack_a) > 3)
	{
		// if ((tmp)->x == hold_in_a)
		// 	start_holding = 1;
		// if (start_holding == 1 && tmp->next->x > hold_in_a)
		// 	hold_in_a = (tmp->next->x);
		// if (start_holding == 1 && (tmp)->x == hold_in_a)
		// {
		// 	if (write(1, "ra\n", 3) == -1)
		// 		return (0);
		// 	first_to_last(stack_a);
		// }
		// else if (start_holding == 0 || (tmp)->x != hold_in_a)
		// {
			if (write(1, "pb\n", 3) == -1)
				return (0);
			push(stack_a, stack_b);
		}
		// else if (start_holding == 1 && tmp->x == hold_in_a)
		// 	tmp =
	// }
	return (1);
}*/
/*
		//FOR CHECKING
		tmp = *stack_a;
			ft_printf("Printing the stack to check \n");
		while (tmp)
		{
			ft_printf("%i \n", tmp->x);
			tmp = tmp->next;
		}
		*/


// TODO: FUNCTION FOR SORT MORE

/*
while there is more than 3 items in stack_a, push to stack b
Sort three in stack_a
while there are items in stack_b
{
	calc_positions(stack_a);
	calc_positions(stack_b);
	calc_targets;
	calc_cost;
	move_to_target;
}
calc_current_pos(stack_a); (may be unnecessary)
min_to_top(stack_a);
*/