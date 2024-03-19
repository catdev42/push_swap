

#include "push_swap.h"

t_node	*ft_dlstnew(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->x = content;
	new->order = 0;
	new->skip = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*ft_dlstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_dlstadd_back(t_node **lst, t_node *node)
{
	t_node	*ptr;

	if (!node || !lst)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	ptr = ft_dlstlast(*lst);
	ptr->next = node;
	node->prev = ptr;
}

void	ft_dlstadd_front(t_node **head, t_node *node)
{
	if (head && node)
	{
		node->next = *head;
		node->next->prev = node;
		*head = node;
	}
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

int	ft_dlstsize(t_node **list)
{
	t_node *lst;
	int i;

	lst = *list;
	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}