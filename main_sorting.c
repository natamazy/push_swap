/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:46:15 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/27 11:46:17 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	offset_counter(int nbr)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	while (i * i <= nbr)
	{
		if (i * i <= nbr)
			a = i;
		if (i * i * i <= nbr)
			b = i;
		i++;
	}
	return (a + b + 1);
}

void	sorting(t_stack *a_sf, t_stack *b_sf, int counter)
{
	int		offset;
	t_list	*node;

	if (!a_sf || !b_sf)
		return ;
	node = a_sf->start;
	offset = offset_counter(a_sf->size);
	while (a_sf->size != 0)
	{
		node = a_sf->start;
		if (node->index <= counter)
		{
			pb(a_sf, b_sf, 1);
			rb(b_sf, 1);
			counter += 1;
		}
		else if (node->index <= counter + offset)
		{
			pb(a_sf, b_sf, 1);
			counter += 1;
		}
		else
			ra(a_sf, 1);
	}
}

void	pushing_back(t_stack *a_sf, t_stack *b_sf)
{
	int		index;
	int		position;

	if (!a_sf || !b_sf)
		return ;
	index = (highest_node(b_sf))->index;
	position = position_of_node_by_index(b_sf, index);
	while (position != INT_MIN)
	{
		if (b_sf->start->index == index && index != INT_MIN)
		{
			pa(a_sf, b_sf, 1);
			index -= 1;
		}
		else if (position > (b_sf->size / 2) && b_sf->size != 0)
			rrb(b_sf, 1);
		else
			rb(b_sf, 1);
		position = position_of_node_by_index(b_sf, index);
	}
}

void	full_sort(t_stack *a_sf, t_stack *b_sf)
{
	if (is_stack_sorted(a_sf) == 1)
		return ;
	if (!a_sf || !b_sf)
		return ;
	if (a_sf->size <= 3)
		small_sort(a_sf);
	else if (a_sf->size <= 5)
		sorting_5(a_sf, b_sf);
	else
	{
		sorting(a_sf, b_sf, 0);
		pushing_back(a_sf, b_sf);
	}
}
