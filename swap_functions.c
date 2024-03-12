/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:28:24 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/20 14:48:46 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int i)
{
	long long	tmp;

	if (stack_a && (stack_a->start != stack_a->finish))
	{
		tmp = stack_a->start->nbr;
		stack_a->start->nbr = stack_a->start->next->nbr;
		stack_a->start->next->nbr = tmp;
	}
	if (i)
		ft_putstr("sa\n", 1);
}

void	sb(t_stack *stack_b, int i)
{
	long long	tmp;

	if (stack_b && (stack_b->start != stack_b->finish))
	{
		tmp = stack_b->start->nbr;
		stack_b->start->nbr = stack_b->start->next->nbr;
		stack_b->start->next->nbr = tmp;
	}
	if (i)
		ft_putstr("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int i)
{
	sa(stack_a, i);
	sb(stack_b, i);
}
