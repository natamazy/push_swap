/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:28:13 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/26 16:41:34 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a_sf, t_stack *b_sf, int i)
{
	t_list	*tmp;

	if (a_sf && b_sf && b_sf->start)
	{
		tmp = b_sf->start;
		b_sf->start = b_sf->start->next;
		if (b_sf->start)
			b_sf->start->prev = NULL;
		tmp->next = a_sf->start;
		if (a_sf->start)
			a_sf->start->prev = tmp;
		a_sf->start = tmp;
		if (a_sf->finish == NULL)
			a_sf->finish = a_sf->start;
		if (b_sf->start == NULL)
			b_sf->finish = NULL;
		a_sf->size++;
		b_sf->size--;
	}
	if (i)
		ft_putstr("pa\n", 1);
}

void	pb(t_stack *a_sf, t_stack *b_sf, int i)
{
	t_list	*tmp;

	if (b_sf && a_sf && a_sf->start)
	{
		tmp = a_sf->start;
		a_sf->start = a_sf->start->next;
		if (a_sf->start)
			a_sf->start->prev = NULL;
		tmp->next = b_sf->start;
		if (b_sf->start)
			b_sf->start->prev = tmp;
		b_sf->start = tmp;
		if (b_sf->finish == NULL)
			b_sf->finish = b_sf->start;
		if (a_sf->start == NULL)
			a_sf->finish = NULL;
		b_sf->size++;
		a_sf->size--;
	}
	if (i)
		ft_putstr("pb\n", 1);
}
