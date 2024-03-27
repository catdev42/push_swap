/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:51:44 by myakoven          #+#    #+#             */
/*   Updated: 2024/03/28 00:36:18 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

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
int					ft_checkdup(int arg_count, char **arr);
int					ft_matrixlen(char **arr);
char				**makearray(int argc, char **argv);

/****SORTING ALGORYTHM****/
int					ft_sort(t_node **stack_a, t_node **stack_b, int arg_count);
int					is_sorted(t_node **stack_a);

int					sort_two(t_node **stack);
int					sort_three(t_node **stack);
int					sort_more(t_node **stack_a, t_node **stack_b);
int					push_all_to_b(t_node **stack_a, t_node **stack_b);
int					p_to_b(t_node **stack_a, t_node **stack_b);
void				actual_sorting(t_node **stack_a, t_node **stack_b);

/****ROTATIONS****/
int					move_to_target(t_node **stack_a, t_node **stack_b);
int					rotate_both(t_node **stack_a, t_node **stack_b,
						t_node *target, t_node *cheapest);
int					reverse_both(t_node **stack_a, t_node **stack_b,
						t_node *target, t_node *cheapest);
int					rotate_a(t_node **stack_a, t_node *target);
int					rotate_b(t_node **stack_b, t_node *cheapest);

/****CALCULATIONS OF COST AND POSITION****/
int					stack_len(t_node **stack);
int					index_stack(t_node **stack);
int					find_target(t_node **stack_a, t_node **stack_b);
t_node				*find_cheapest(t_node **stack);
t_node				*find_min(t_node **stack);
int					bonus(t_node *a, t_node *b, int len_a, int len_b);
void				calc_cost(t_node **stack_a, t_node **stack_b);
/***ERROR & CLEAR*/
int					ft_clean(char **arg_arr, t_node **stack_a, t_node **stack_b,
						int error);
int					error_fail(void);
int					free_array(char **arr);

/***DEBUGGING***/
void				print_all(t_node **stack_a, t_node **stack_b);

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

#endif