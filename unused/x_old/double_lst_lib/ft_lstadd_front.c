/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:04:23 by myakoven          #+#    #+#             */
/*   Updated: 2024/01/31 01:46:27 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_dlist **head, t_dlist *new)
{
	if (head && new)
	{
		new->next = *head;
		new->next->prev = new;
		*head = new;
	}
}
