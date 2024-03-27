#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_dlist
{
	int				x;
	int				pos;
	int				above_mid;
	struct s_dlist	*target;
	int				cost;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_node;

int					last_to_first(t_node **stack);
int					push(t_node **stack_from, t_node **stack_to);
int					swap(t_node **stack);
int					first_to_last(t_node **stack);
t_node				*ft_dlstnew(int content);
long				ft_atol(const char *nptr);
t_node				*ft_init_list(int argcount, char **arg_arr);
t_node				**ft_dlstclear(t_node **lst);

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	t_node	*tmp;

	stack_a = ft_init_list(argc, argv);
	// 4 67 6  3 87 23
	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		printf("ITEM %i, at address %p \n tmp->x = %i,\n tmp->pos = %i,\n tmp->above_min = %i,\n tmp->target->x = %i,\n tmp->cost = %i,\n tmp->prev = %p, \n tmp->next = %p", i, tmp,
				tmp->x,
				tmp->pos,
				tmp->above_mid,
				tmp->target->x,
				tmp->cost,
				tmp->prev,
				tmp->next);
		tmp = tmp->next;
		i++;
	}
	swap(&stack_a);
	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		printf("ITEM %i, at address %p \n tmp->x = %i,\n tmp->pos = %i,\n tmp->above_min = %i,\n tmp->target->x = %i,\n tmp->cost = %i,\n tmp->prev = %p, \n tmp->next = %p", i, tmp,
				tmp->x,
				tmp->pos,
				tmp->above_mid,
				tmp->target->x,
				tmp->cost,
				tmp->prev,
				tmp->next);
		tmp = tmp->next;
		i++;
	}
	push(&stack_a, &stack_b);
	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		printf("ITEM %i, at address %p \n tmp->x = %i,\n tmp->pos = %i,\n tmp->above_min = %i,\n tmp->target->x = %i,\n tmp->cost = %i,\n tmp->prev = %p, \n tmp->next = %p", i, tmp,
				tmp->x,
				tmp->pos,
				tmp->above_mid,
				tmp->target->x,
				tmp->cost,
				tmp->prev,
				tmp->next);
		tmp = tmp->next;
		i++;
	}
	tmp = stack_b;
	i = 0;
	while (tmp)
	{
		printf("ITEM %i, at address %p \n tmp->x = %i,\n tmp->pos = %i,\n tmp->above_min = %i,\n tmp->target->x = %i,\n tmp->cost = %i,\n tmp->prev = %p, \n tmp->next = %p", i,
				tmp,
				tmp->x,
				tmp->pos,
				tmp->above_mid,
				tmp->target->x,
				tmp->cost,
				tmp->prev,
				tmp->next);
		tmp = tmp->next;
		i++;
	}
}
t_node	*ft_init_list(int argcount, char **arg_arr)
{
	int		i;
	t_node	*temp;
	t_node	*head;
	t_node	*last;

	i = 1;
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

int	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*temp_move;
	t_node	*temp_newhead;

	if (!stack_from || !*stack_from)
	{
		printf("The from stack is empty, nothing more to push");
		return (0);
	}
	temp_move = *stack_from;
	temp_newhead = temp_move->next;
	if (stack_from && stack_to)
	{
		if (*stack_to)
			temp_move->next = *stack_to;
		else
			temp_move->next = NULL;
		if (stack_to && *stack_to)
			(*stack_to)->prev = temp_move;
		*stack_to = temp_move;
		*stack_from = temp_newhead;
	}
	return (1);
}

int	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack)
	{
		printf("nothing to swap, stack empty (error)");
		return (0);
	}
	first = *stack;
	second = (*stack)->next;
	// temp = first;
	first->next = first->next->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
	return (1);
}

int	first_to_last(t_node **stack)
{
	t_node	*templast;
	t_node	*newstart;
	t_node	*newlast;

	if (!*stack || !stack)
	{
		printf("nothing to swap, stack empty(error)");
		return (0);
	}
	newstart = (*stack)->next;
	templast = *stack;
	while (templast->next)
		templast = templast->next;
	templast->next = *stack;
	newlast = templast->next;
	newlast->next = NULL;
	newlast->prev = templast;
	*stack = newstart;
	newstart->prev = NULL;
	return (1);
}

int	last_to_first(t_node **stack)
{
	t_node	*newstart;

	// t_node	*tmp;
	// tmp = *stack;
	if (!*stack || !stack)
	{
		printf("nothing to swap, stack is empty (error)");
		return (0);
	}
	newstart = *stack;
	while (newstart->next)
	{
		newstart = newstart->next;
	}
	newstart->prev->next = NULL;
	newstart->next = *stack;
	*stack = newstart;
	newstart->next->prev = newstart;
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '+')
			nptr++;
		else if (*nptr == '-')
		{
			sign = -1;
			nptr++;
		}
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (num * sign);
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
