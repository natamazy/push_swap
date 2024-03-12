/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:29:56 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/26 11:29:58 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *sf)
{
	t_list	*highest;

	highest = highest_node(sf);
	if (sf->start == highest)
		ra(sf, 1);
	else if (sf->start->next == highest)
		rra(sf, 1);
	if (sf->start->nbr > sf->start->next->nbr)
		sa(sf, 1);
}
