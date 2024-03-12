/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:13:10 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/20 14:51:18 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, int i)
{
	t_list	*tmp;

	if (stack_a && (stack_a->start != stack_a->finish))
	{
		tmp = stack_a->finish;
		stack_a->finish = stack_a->finish->prev;
		stack_a->finish->next = NULL;
		tmp->prev = NULL;
		stack_a->start->prev = tmp;
		tmp->next = stack_a->start;
		stack_a->start = tmp;
	}
	if (i)
		ft_putstr("rra\n", 1);
}

void	rrb(t_stack *stack_b, int i)
{
	t_list	*tmp;

	if (stack_b && (stack_b->start != stack_b->finish))
	{
		tmp = stack_b->finish;
		stack_b->finish = stack_b->finish->prev;
		stack_b->finish->next = NULL;
		tmp->prev = NULL;
		stack_b->start->prev = tmp;
		tmp->next = stack_b->start;
		stack_b->start = tmp;
	}
	if (i)
		ft_putstr("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int i)
{
	rra(stack_a, i);
	rrb(stack_b, i);
}
