/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:16:10 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/20 14:50:51 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int i)
{
	t_list	*tmp;

	if (stack_a && (stack_a->start != stack_a->finish))
	{
		tmp = stack_a->start;
		stack_a->start = stack_a->start->next;
		stack_a->start->prev = NULL;
		tmp->prev = stack_a->finish;
		stack_a->finish->next = tmp;
		stack_a->finish = tmp;
		stack_a->finish->next = NULL;
	}
	if (i)
		ft_putstr("ra\n", 1);
}

void	rb(t_stack *stack_b, int i)
{
	t_list	*tmp;

	if (stack_b && (stack_b->start != stack_b->finish))
	{
		tmp = stack_b->start;
		stack_b->start = stack_b->start->next;
		stack_b->start->prev = NULL;
		tmp->prev = stack_b->finish;
		stack_b->finish->next = tmp;
		stack_b->finish = tmp;
		stack_b->finish->next = NULL;
	}
	if (i)
		ft_putstr("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int i)
{
	ra(stack_a, i);
	rb(stack_b, i);
}
