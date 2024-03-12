/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:50:49 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/26 18:10:59 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *sf)
{
	t_list	*tmp;

	if (!sf)
		return (0);
	tmp = sf->start;
	while (tmp->next)
	{
		if (tmp->nbr < tmp->next->nbr)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp == sf->finish)
		return (1);
	return (0);
}

int	length_of_stack(t_stack *sf)
{
	t_list	*tmp;
	int		length;

	if (!sf)
		return (INT_MIN);
	tmp = sf->start;
	length = 0;
	while (tmp)
	{
		length += 1;
		tmp = tmp->next;
	}
	return (length);
}

t_list	*highest_node(t_stack *sf)
{
	t_list	*tmp;
	t_list	*highest;

	if (!sf)
		return (NULL);
	tmp = sf->start;
	highest = sf->start;
	while (tmp)
	{
		if (tmp->index > highest->index)
			highest = tmp;
		tmp = tmp->next;
	}
	return (highest);
}

int	position_of_node(t_stack *sf, t_list *node)
{
	t_list	*tmp;
	int		i;

	tmp = sf->start;
	i = 0;
	while (tmp)
	{
		if (tmp == node)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	position_of_node_by_index(t_stack *sf, int i)
{
	t_list	*tmp;
	int		position;

	tmp = sf->start;
	position = 0;
	while (tmp)
	{
		if (tmp->index == i)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (INT_MIN);
}
