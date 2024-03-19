/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:51:44 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/09 23:28:02 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

typedef struct s_dlist
{
	int				x;
	int				order;
	int				skip;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_node;

/****CHECK INPUT && INITIALIZE****/
t_node				*ft_init_list(int argc, char **argv);
int					ft_checkarray(int argc, char **arr);
int					ft_matrixlen(char **arr);
int					error_fail(void);

/****SPLIT and MAKEARRAY****/
char				**makearray(int argc, char **argv);
char				**ft_split_ps(char const *s, char c);
char				**ft_free_split_ps(char **arr, int index);
size_t				ft_wordcount_ps(char const *s, char c);
char				**free_array(char **arr);

/****MOVES****/
int					push(t_node **stack_from, t_node **stack_to);
int					swap(t_node **stack);
int					first_to_last(t_node **stack);
int					last_to_first(t_node **stack);

/****DOUBLE LINKED LIST BASIC OPS****/
void				ft_dlstadd_front(t_node **head, t_node *node);
void				ft_dlstadd_back(t_node **lst, t_node *node);
t_node				*ft_dlstlast(t_node *lst);
t_node				*ft_dlstnew(int content);
t_node				**ft_dlstclear(t_node **lst);
int					ft_dlstsize(t_node **list);

/*
t_list				*ft_lstnew(void *content);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **first, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
*/
#endif