/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firsts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 03:59:48 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/09 14:56:51 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// store total number of items in each struct... lets say 10

int	determine_who_stays(t_node **stack)
{
	int	keepstart;
	int	totalsize;
	int	howmanyafter[totalsize];
    int numbersinorder[totalsize];
	int	i;

	// compare_arr[0] = totalsize;
    // numbersinorder[0] =totalsize;
	i = 0;
	while (i < totalsize)
    {
        numbersinorder[i] = ft_next_smallest(stack);
        howmanyafter[i] = ft_howmanyafter(stack, numbersinorder[i]);
    }
}

int ft_howmanyafter(t_node **stack, int starting_num)
{
    int howmany;
    int recordnum;
    t_node *temp;

    while (temp->x != starting_num)
        temp = temp->next;
    
    
}

int	ft_next_smallest(t_node **stack)
{
	t_node	*temp;
	int		number;
	int		number_temp;
	int		i;

	i = 0;
	temp = *stack;
	number = temp->x;
	while (temp)
	{
		temp = temp->next;
		while (temp->skip)
			temp = temp->next;
		number_temp = temp->x;
		if (number > number_temp)
			number = number_temp;
	}
	temp = *stack;
	while (temp->x != number)
	{
		temp = temp->next;
	}
	temp->skip = 1;
	return (number);
}

// find the smallest number in the first half of numbers... so smallest number

// give indexes to each number in order...

// find the smallest number,
// check how many numbers in increasing order there are

// in theory there are N-1 possibilities (because the biggest number will have just 1 at the end...)

// so if total number is 10, I can allocate an INT array of 11 characters,
//making the 0 index keep how many numbers are stored in the array...

	// the number at index 1 will keep how many numbers (in order) will follow the smallest number in the sequence,
	// the number at index 10 (or arr[(arr[0])]) will always be 1

	// then we chose the number with greatest number of numbers following it. this can potentially save up hundreds of unnecessary moves.... we basically keep all ordered number in stack a at the very start.
