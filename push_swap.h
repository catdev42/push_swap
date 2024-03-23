/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:51:44 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/23 22:12:09 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// typedef struct s_dlist
// {
// 	int				nr;
// 	int				index;
// 	int				skip;
// 	struct s_dlist	*prev;
// 	struct s_dlist	*next;
// }					t_node;

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

/****MAIN.C: CHECK INPUT && INITIALIZE****/
t_node				*ft_init_list(int argc, char **argv);
int					ft_checkarray(int argc, char **arr);
int					ft_matrixlen(char **arr);
char				**makearray(int argc, char **argv);

/****SORTING ALGORYTHM****/

int					ft_sort(t_node **stack_a, t_node **stack_b, int arg_count);
int					is_sorted(t_node **stack_a);

int					sort_two(t_node **stack);
int					sort_three(t_node **stack);
int					sort_more(t_node **stack_a, t_node **stack_b);
int					push_all_to_b(t_node **stack_a, t_node **stack_b);

/****CALCULATIONS OF COST AND POSITION****/
int					stack_len(t_node **stack);
int					index_stack(t_node **stack);
int					find_target(t_node **stack_a, t_node **stack_b);
t_node				*find_cheapest(t_node **stack);
t_node				*find_min(t_node *stack);
int					bonus(t_node *a, t_node *b, int len_a, int len_b);
int					calc_cost(t_node **stack_a, t_node **stack_b);
/***ERROR & CLEAR*/
int					ft_clean(char **arg_arr, t_node **stack_a, t_node **stack_b,
						int error);
int					error_fail(void);
int					free_array(char **arr);
// char				**ft_free_split_ps(char **arr, int index);

/****SPLIT and MAKEARRAY****/
// char				**ft_split_ps(char const *s, char c);
// size_t				ft_wordcount_ps(char const *s, char c);

/****MOVES****/
int					push(t_node **stack_from, t_node **stack_to);
int					swap(t_node **stack);
int					first_to_last(t_node **stack);
int					last_to_first(t_node **stack);

/****LIST UTILS****/
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