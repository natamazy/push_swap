/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:26:52 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/26 18:04:00 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Structures
typedef struct s_list
{
	long long		nbr;
	struct s_list	*next;
	struct s_list	*prev;
	int				index;
}		t_list;

typedef struct s_stack
{
	struct s_list	*start;
	struct s_list	*finish;
	int				size;
}		t_stack;

// Swap functions
void		sa(t_stack *stack_a, int i);
void		sb(t_stack *stack_b, int i);
void		ss(t_stack *stack_a, t_stack *stack_b, int i);

// Push functions
void		pa(t_stack *stack_a, t_stack *stack_b, int i);
void		pb(t_stack *stack_a, t_stack *stack_b, int i);

// Rotate functions
void		ra(t_stack *stack_a, int i);
void		rb(t_stack *stack_b, int i);
void		rr(t_stack *stack_a, t_stack *stack_b, int i);

// Reverse rotate functions
void		rra(t_stack *stack_a, int i);
void		rrb(t_stack *stack_b, int i);
void		rrr(t_stack *stack_a, t_stack *stack_b, int i);

// Utilities
t_list		*ft_lstnew(long long nbr, t_list *prev);
void		ft_putstr(char *s, int fd);
size_t		ft_strlen(const char *s);
long long	ft_atoi(const char *str, int i, int j, int flag);
int			is_digit_space_sign(int c);
int			ft_isdigit(int c);
int			ft_str_isdigit(char *str);
int			print_error(char *message);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_lstclear(t_list **lst);
t_list		*highest_node(t_stack *sf);
int			length_of_stack(t_stack *sf);
int			is_stack_sorted(t_stack *sf);
int			position_of_node(t_stack *sf, t_list *node);
int			position_of_node_by_index(t_stack *sf, int i);

// Stack parsing and validation
int			is_everything_legit(int count, char *arguments[]);
char		**ft_split(char const *s, char c);
void		validation(int count, char *arguments[],
				t_stack *a_sf, t_list *node);
int			validating_all_together(int count, char *arguments[],
				t_stack *a_sf, t_list *node);
int			space_checker(char *argv[], int i, int j);

// Clear functions
void		free_split_and_stack(char **numbers, t_stack *a_sf);
void		free_split(char **numbers);
void		free_sf(t_stack *sf);
void		go_to_next(t_stack *sf, t_list *node);
void		free_stack(t_stack *a_sf, t_stack *b_sf, t_list *node);

// Sorting functions
void		small_sort(t_stack *sf);
void		sorting_5(t_stack *a_sf, t_stack *b_sf);
void		sorting(t_stack *a_sf, t_stack *b_sf, int counter);
void		pushing_back(t_stack *a_sf, t_stack *b_sf);
void		full_sort(t_stack *a_sf, t_stack *b_sf);

// Indexing functions
void		zero_indexing(t_stack *sf);
void		indexing(t_stack *sf);

// Checker utilities
int			swap_check_do(char *command, t_stack *a_sf, t_stack *b_sf);
int			push_check_do(char *command, t_stack *a_sf, t_stack *b_sf);
int			rotate_check_do(char *command, t_stack *a_sf, t_stack *b_sf);
int			rev_rotate_check_do(char *command, t_stack *a_sf, t_stack *b_sf);

#endif